# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#

def mergeTwoLinkedLists(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1
    
    a = l1
    b = l2
    if a.value < b.value:
        l = ListNode(a.value)
        a = a.next
    else:
        l = ListNode(b.value)
        b = b.next
    c = l
    
    while a or b:
        if not a:
            c.next = b
            break
        if not b:
            c.next = a
            break
        
        if a.value < b.value:
            c.next = ListNode(a.value)
            a = a.next
        else:
            c.next = ListNode(b.value)
            b = b.next
        c = c.next
    
    return l
