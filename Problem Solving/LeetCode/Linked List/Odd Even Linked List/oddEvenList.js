/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if (head === null || head.next === null) {
        return head;
    }
    
    let i = 1;
    let currentNode = head;
    let nextNode = null;
    let oddTail = head;
    const evenHead = head.next;
    while (currentNode.next.next !== null) {
        nextNode = currentNode.next;
        currentNode.next = currentNode.next.next;
        if (i % 2 === 1) {
            oddTail = currentNode.next;
        }
        currentNode = nextNode;
        ++i;
    }
    
    if (i % 2 === 0) {
        currentNode.next = null;
    }
    oddTail.next = evenHead;
    
    return head;
};