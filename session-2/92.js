/**
 * Reverse Linked List II
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    
    var reverse = function (head, num) {
        var prevNode = null;
        var curNode = head;
        var tail = head;
        
        while (num > 0 && curNode) {
            var tmpNode = curNode.next;
            curNode.next = prevNode;
            prevNode = curNode;
            curNode = tmpNode;
            num -= 1;
        }
        
        return [prevNode, tail, curNode];
    }
    
    if (!head || m === n) {
        return head;
    }
    var fake_head = new ListNode(0);
    fake_head.next = head;
    
    var prevNode = fake_head;
    var curNode = head;
    for (var i = 1; i < m; i += 1) {
        prevNode = curNode;
        curNode = curNode.next;
    }
 
    var tmp = reverse(prevNode.next, n-m+1);
    prevNode.next = tmp[0];
    tmp[1].next = tmp[2];
    
    return fake_head.next;
};
