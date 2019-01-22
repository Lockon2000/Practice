def compact(iterable):
    iterator = iter(iterable)
    
    try:
        firstItem = next(iterator)
        yield firstItem

        lastItem = firstItem
        while True:
            item = next(iterator)
            if item != lastItem:
                lastItem = item
                yield item
    except StopIteration:
        return
