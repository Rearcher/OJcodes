// Remove Duplicates from Sorted List
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    
    var curNode = head;
    
    while (curNode) {
        var tempNode = curNode.next;
        if (tempNode === null) break;
        
        if (curNode.val === tempNode.val) {
            curNode.next = tempNode.next;
            tempNode.next = null;
        } else {
            curNode = curNode.next;
        }
    }
    
    return head;
};
