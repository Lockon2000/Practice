"""
In-place bottom-up mergesort implementation
"""


def mergesort(lst, b=0, e=None):
    if e == None:
        e = len(lst) - 1
    length = e - b + 1

    l = 1
    while l < length:
        for i in range(b, e + 1, 2 * l):
            if i + l <= e:
                merge(lst, i, i + l, e)

        l *= 2


# In-place sorted ((adjacent)) sublists merger helper function
# lst: refrence to the list
# i: index of the first element of the first list
# l: index of the first element of the second list
# e: index of the last element of the second list (needed as the second sublist may be smaller than the first)
def merge(lst, i, l, e):
    fullLength = l - i
    n = l + fullLength if e + 1 >= l + fullLength else e + 1

    while i < l and l < n:
        if lst[i] <= lst[l]:
            i += 1
        else:
            tmp = lst[l]
            for m in range(l, i, -1):
                lst[m] = lst[m - 1]
            lst[i] = tmp

            l += 1


# # Testing `merge`

# lst = [1, 3, 5, 7, 2, 4, 6, 8]

# merge(lst, 0, 4, len(lst) - 1)
# print(lst)


# Testing `mergesort`

# test1 = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
# mergesort(test1)
# print(test1)

from timeit import timeit

t = timeit(
    "lst = [randint(-10_000, 10_000) for i in range(100_000)]; mergesort(lst)",
    setup="from random import randint",
    globals=globals(),
    number=1
)

print(t)