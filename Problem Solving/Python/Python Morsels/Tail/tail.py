def tail(iterable, tailLength):
    result = []
    
    if tailLength > 0:
        iterator = iter(iterable)

        try:
            for _ in range(tailLength):
                result.append(next(iterator))
        except StopIteration:
            pass

        try:
            while True:
                result.append(next(iterator))
                del result[0]
        except StopIteration:
            pass

    return result

