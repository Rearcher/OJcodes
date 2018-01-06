// remove Nth node from end of list
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    if (head === null) return head;
    
    var pNode = head, len = 0;
    while (pNode) {
        pNode = pNode.next;
        len++;
    }
    
    if (len === n) return head.next;
    
    var qNode = head;
    pNode = head;
    for (var i = 0; i < n; i++) {
        pNode = pNode.next;
    }
    while (pNode.next) {
        pNode = pNode.next;
        qNode = qNode.next;
    }
    var tNode = qNode.next;
    qNode.next = tNode.next;
    tNode = null;
    
    return head;
};
