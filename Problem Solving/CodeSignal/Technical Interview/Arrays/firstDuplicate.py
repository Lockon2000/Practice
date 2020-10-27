a = [2, 4, 3, 4, 2]


# Time complexity exceeding O(n) but space complexity O(1)
def firstDuplicate(a):
    for i, b in enumerate(a):
        if b in a[:i]:
            return b
    return -1


# Time complexity O(n) but space complexity exceeding O(1)
def firstDuplicate2(a):
    b = [0]*len(a)
    
    for i in a:
        if b[i-1] == 0:
            b[i-1] += 1
        else:
            return i
    
    return -1


# Time complexity O(n) and space complexity O(1) -- Winner!!
def firstDuplicate3(array):
    length = len(array)
    
    for i in array:
        if i > length:
            i -= length

        if array[i-1] <= length:
            array[i-1] += length
        else:
            return i
    
    return -1


print(firstDuplicate(a))
print(firstDuplicate2(a))
print(firstDuplicate3(a))