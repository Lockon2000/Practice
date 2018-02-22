# Definition for singly-linked list:
class ListNode(object):
  def __init__(self, x):
    self.value = x
    self.next = None

def p(l):
    while (l):
        print(l.value)
        l = l.next

l = ListNode(3)
j = l

for i in [1, 2, 3, 4, 5]:
    j.next = ListNode(i)
    j = j.next

k = 3


def removeKFromList(l, k):
    prevN = None
    nextN = None

    while l and (l.value == k):
            l = l.next
    else:
        headN = l

    while l:
        nextN = l.next
        if l.value == k:
            prevN.next = nextN
            l = nextN
        else:
            prevN = l
            l = nextN
    
    return headN

def removeKFromList2(l, k):
    c = l
    while c:
        if c.next and c.next.value == k:
            c.next = c.next.next
        else:
            c = c.next
    return l.next if l and l.value == k else l

p(removeKFromList2(l,k))

