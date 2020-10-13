"""Implement quick sort in Python.
Input a list.
Output a sorted list."""


def quicksort(array):
    p = len(array) - 1

    i = 0
    while i < p:
        if array[p] < array[i]:
            array.append(array.pop(i))
            p = p - 1
        else:
            i += 1

    if p > 1:
        array[:p] = quicksort(array[:p])
    if len(array) - 1 - p > 1:
        array[p + 1 :] = quicksort(array[p + 1 :])
    
    return array


test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
quicksort(test)
print(test)