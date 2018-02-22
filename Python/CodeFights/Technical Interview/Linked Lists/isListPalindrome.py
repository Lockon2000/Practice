# Definition for singly-linked list:
# class ListNode(object):
#   def __init__(self, x):
#     self.value = x
#     self.next = None
#
def isListPalindrome(l):
    if not l:
        return True
    
    a = l
    n = 1
    while a.next:
        a.next.prev = a
        a = a.next
        n += 1
    
    for i in range(n//2):
        if a.value != l.value:
            return False
        a = a.prev
        l = l.next
    
    return True