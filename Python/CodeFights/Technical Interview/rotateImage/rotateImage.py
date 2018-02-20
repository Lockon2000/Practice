def rotateImage1(a):
    length = len(a)

    for i in range(length):
        for j in range(i+1,length):
            tmp = a[i][j]
            a[i][j] = a[j][i]
            a[j][i] = tmp
    
    for i in range(length):
        a[i].reverse()

    return a

def rotateImage2(a):
    return [[x[i] for x in a][::-1] for i in range(len(a))]

def rotateImage3(a):
    return zip(*a[::-1])

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]

print(rotateImage1(a))
