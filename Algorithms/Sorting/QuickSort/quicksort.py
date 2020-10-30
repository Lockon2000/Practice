"""
In-place quicksort implementation
"""


def quicksort(lst, b=0, e=None):
    if e == None:
        e = len(lst) - 1

    p = e
    i = b
    while i < p:
        if lst[p] < lst[i]:
            # bring lst[i] after lst[p] through two swaps
            lst[i], lst[p - 1] = lst[p - 1], lst[i]
            lst[p - 1], lst[p] = lst[p], lst[p - 1]

            p = p - 1
        else:
            i += 1

    if p > b + 1:
        quicksort(lst, b, p - 1)
    if p < e - 1:
        quicksort(lst, p + 1, e)

    return lst


test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
quicksort(test)
print(test)