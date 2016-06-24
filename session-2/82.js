/**
 * Remove Duplicates from Sorted List II
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
     if (!head || !head.next) {
        return head;
    }
   	
    var fake_head = new ListNode(0);
    fake_head.next = null;
    
    var slowNode = fake_head;
    var fastNode = head, cnt;
    
    while (fastNode) {
        cnt = 1;
        while (fastNode && fastNode.next && 
            fastNode.val == fastNode.next.val) {
            fastNode = fastNode.next;
            cnt += 1;
        }
        
        if (cnt == 1) {
            slowNode.next = fastNode;
            slowNode = slowNode.next;
        }
        
        if (fastNode) {
            fastNode = fastNode.next;
        }   
    }

	slowNode.next = null;
    
    return fake_head.next;
};
