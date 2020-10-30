"""
Bottom-up mergesort implementation
"""

from more_itertools import grouper


def mergesort(lst):
    lst = [[i] for i in lst]

    while len(lst) > 1:
        lst = [merge(lst1, lst2) for lst1, lst2 in grouper(lst, 2, [])]

    return [*lst]


def merge(lst1, lst2):
    result = []
    while len(lst1) > 0 and len(lst2) > 0:
        if lst1[0] <= lst2[0]:
            result.append(lst1.pop(0))
        else:
            result.append(lst2.pop(0))

    if len(lst1) > 0:
        result.extend(lst1)
    else:
        result.extend(lst2)

    return result


# # Testing `merge`

# lst1 = [1, 3, 5, 7]
# lst2 = [2, 4, 6, 8]

# print(merge(lst1, lst2))


# Testing `mergesort`

# test1 = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
# print(mergesort(test1))

from timeit import timeit

t = timeit(
    "lst = [randint(-10_000, 10_000) for i in range(1_000_000)]; mergesort(lst)",
    setup="from random import randint",
    globals=globals(),
    number=1
)

print(t)
