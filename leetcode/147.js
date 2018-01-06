/**
 * Insertion Sort List
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
var insertionSortList = function(head) {
    
    if (!head) return head;
    
    var fake_head = new ListNode(0);
    fake_head.next = head;
    
    var prevNode = fake_head;
    var curNode = fake_head.next;
    
    while (curNode) {
        
        var tmpPrev = fake_head;
        var tmpCur = fake_head.next;
        while (tmpCur !== curNode && tmpCur.val < curNode.val) {
            tmpPrev = tmpCur;
            tmpCur = tmpCur.next;
        }
        
        if (tmpCur === curNode) {
            prevNode = curNode;
            curNode = curNode.next;
        } else {
            prevNode.next = curNode.next;
            curNode.next = tmpCur;
            tmpPrev.next = curNode;
            
            curNode = prevNode.next;
        }
        
    }
    
    return fake_head.next;
};
