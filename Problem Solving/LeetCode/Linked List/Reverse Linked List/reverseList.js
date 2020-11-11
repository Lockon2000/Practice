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
var reverseList = function(head) {
    if (head === null) {
        return head;
    }
    
    let result = null;
    if (head.next !== null) {
        result = reverseList(head.next);
        head.next.next = head;
        head.next = null;
    } else {
        result = head;
    }
    
    return result;
};