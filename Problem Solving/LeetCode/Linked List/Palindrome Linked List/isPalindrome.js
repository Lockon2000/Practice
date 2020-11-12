/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if (!head) {
        return head;
    }
    
    let currentNode = head;
    let previousNode = null;
    while (currentNode.next) {
        currentNode.prev = previousNode;
        previousNode = currentNode;
        currentNode = currentNode.next;
    }
    currentNode.prev = previousNode;
    
    const tail = currentNode;
    let currentNodeHead = head;
    let currentNodeTail = tail;
    while (currentNodeHead !== currentNodeTail) {
        if (currentNodeHead.val !== currentNodeTail.val) return false;
        currentNodeHead = currentNodeHead.next;
        currentNodeTail = currentNodeTail.prev;
    }
    
    return true;
};