"""
Bottom-up mergesort implementation 3
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


# Sorted ((adjacent)) sublists merger helper function
# lst: refrence to the list
# i: index of the first element of the first list
# l: index of the first element of the second list
# e: indes of the last elemen of the lst (needed as the second sublist may be smaller than the first)
def merge(lst, i, l, e):
    b = i
    fullLength = l - i
    m = i + fullLength
    n = l + fullLength if e + 1 >= l + fullLength else e + 1

    result = []
    while i < m and l < n:
        if lst[i] <= lst[l]:
            result.append(lst[i])

            i += 1
        else:
            result.append(lst[l])

            l += 1
    
    if i < m:
        result.extend(lst[i:m])
    else:
        result.extend(lst[l:n])

    lst[b:n] = result


# # Testing `merge`

# lst = [1, 3, 5, 7, 10, 2, 4, 6, 8]

# merge(lst, 0, 5, len(lst) - 1)
# print(lst)


# Testing `mergesort`

# test1 = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
# mergesort(test1)
# print(test1)

from timeit import timeit

t = timeit(
    "lst = [randint(-10_000, 10_000) for i in range(1_000_000)]; mergesort(lst); print(lst[::100]);",
    setup="from random import randint",
    globals=globals(),
    number=1,
)

print(t)