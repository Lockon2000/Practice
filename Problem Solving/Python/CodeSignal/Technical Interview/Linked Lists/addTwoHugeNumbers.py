# Singly-linked lists are already defined with this interface:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None

def addTwoHugeNumbers(a, b):
    # Get tail of `a` and `b`
    aTail, lengthOfa = makeDoublyLinkedList(a)
    bTail, lengthOfb = makeDoublyLinkedList(b)

    # Create the new list and store the sum of the two lists in it
    cCurrent = ListNode(0)
    cCurrent.next = None
    aCurrent, bCurrent = aTail, bTail
    for _ in range(max(lengthOfa, lengthOfb)):
        raw = (cCurrent.value +
               (aCurrent.value if aCurrent else 0) +
               (bCurrent.value if bCurrent else 0))
        cCurrent.value = raw % 10000
        cCurrent.previous = ListNode(raw // 10000)
        aCurrent = aCurrent.previous if aCurrent else None
        bCurrent = bCurrent.previous if bCurrent else None
        cCurrent.previous.next = cCurrent
        cCurrent = cCurrent.previous
    
    if cCurrent.value > 0:
        return cCurrent
    else:
        return cCurrent.next


def makeDoublyLinkedList(listHead):
    current = listHead
    previous = None
    length = 0
    while current != None:
        current.previous = previous
        previous = current
        current = current.next
        length += 1
    
    return previous, length



# Testing and Debugging #

class ListNode(object):
  def __init__(self, x):
    self.value = x
    self.next = None

def traverseAndPrint(listHead):
    current = listHead
    while current != None:
        print(current.value)
        current = current.next
    
    print()

# a = ListNode(9876)
# a.next = ListNode(5432)
# a.next.next = ListNode(1999)

a = ListNode(1)

# b = ListNode(1)
# b.next = ListNode(8001)

b = ListNode(9999)
b.next = ListNode(9999)
b.next.next = ListNode(9999)
b.next.next.next = ListNode(9999)
b.next.next.next.next = ListNode(9999)
b.next.next.next.next.next = ListNode(9999)

traverseAndPrint(a)
traverseAndPrint(b)
traverseAndPrint(addTwoHugeNumbers(a,b))
