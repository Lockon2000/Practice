def tailRecursion(m, n):
    if m == 0 or n == 0:
        print(m, n)
        return 1
    else:
        return 2 * tailRecursion(m-1, n+1)

def tailRecursion_iter1(m, n):
    result = 1

    while m != 0 and n != 0:
        result *= 2
        m, n = m-1, n+1

    print(m, n)
    return result

def tailRecursion_iter2(m, n):
    acc = 1

    while m != 0 and n != 0:
        (m, n, acc) = (m-1, n+1, 2 * acc)

    print(m, n)
    return acc

# tests

print(f"{tailRecursion(5, 5)=}")
print(f"{tailRecursion(5, 10)=}")
print(f"{tailRecursion(5, -5)=}")

print(f"{tailRecursion_iter1(5, 5)=}")
print(f"{tailRecursion_iter1(5, 10)=}")
print(f"{tailRecursion_iter1(5, -5)=}")

print(f"{tailRecursion_iter2(5, 5)=}")
print(f"{tailRecursion_iter2(5, 10)=}")
print(f"{tailRecursion_iter2(5, -5)=}")