def multimax(iterable, key=lambda x: x):
    result = []

    for i in iterable:
        if len(result) == 0:
            result.append(i)
        else:
            if key(i) > key(result[-1]):
                result = [i]
            elif key(i) == key(result[-1]):
                result.append(i)

    return result
