// palindrome linked list
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var reverse = function(head) {
    if (!head || !head.next) return head;
    
    var prevNode = null, curNode = head;
    var nextNode = null, reverseHead;
    while (curNode) {
        nextNode = curNode.next;
        if (!nextNode) reverseHead = curNode;
        
        curNode.next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    
    return reverseHead;
} 

var isPalindrome = function(head) {
    if (!head || !head.next) return true;
    
    var fastNode = head, slowNode = head;
    while (fastNode.next && fastNode.next.next) {
        fastNode = fastNode.next.next;
        slowNode = slowNode.next;
    }
    
    slowNode.next = reverse(slowNode.next);
    slowNode = slowNode.next;
    
    while (slowNode) {
        if (head.val !== slowNode.val) return false;
        head = head.next;
        slowNode = slowNode.next;
    }
    return true;
};
