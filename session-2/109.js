/**
 * Convert Sorted List to Binary Search Tree
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {TreeNode}
 */
function midNode (head) {
        
    if (!head) return head;
        
    var fast = head;
    var slow = head;
    var prev = slow;
        
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
        
    prev.next = null;
    return slow;
}
 
var sortedListToBST = function(head) {
    
    if (!head) return null;
    if (head && !head.next) {
		return new TreeNode(head.val);
    }
    
    var mid = midNode(head);
    var leftHead = head;
    var rightHead = mid.next;
    mid.next = null;
    
    var treeHead = new TreeNode(mid.val);
    var leftNode = sortedListToBST(leftHead);
    var rightNode = sortedListToBST(rightHead);
    
    if (leftNode) {
        treeHead.left = leftNode;
    }
    
    if (rightNode) {
        treeHead.right = rightNode;
    }
    
    return treeHead;
};
