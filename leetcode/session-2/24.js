// Swap Node in Pairs
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
var swapPairs = function(head) {
    var fake_root = new ListNode(0);
    fake_root.next = head;
    
    var preNode = fake_root;
    var curNode = preNode.next;
    
    while (curNode && curNode.next) {
        var nexNode = curNode.next;
        preNode.next = nexNode;
        curNode.next =nexNode.next;
        nexNode.next = curNode;
        
        preNode = curNode;
        curNode = curNode.next;
    }
    
    return fake_root.next;
};
