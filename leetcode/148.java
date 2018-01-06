/**
 * 148. Sort List
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) 
            return head;
        
        ListNode prev = null, slow = head, fast = head;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        prev.next = null;
        
        return merge(sortList(head), sortList(slow));
    }
    
    private ListNode merge(ListNode h1, ListNode h2) {
        ListNode fake_head = new ListNode(0);
        ListNode c = fake_head;
        while (h1 != null && h2 != null) {
            if (h1.val < h2.val) {
                c.next = h1;
                h1 = h1.next;
            } else {
                c.next = h2;
                h2 = h2.next;
            }
            c = c.next;
        }
        
        if (h1 != null) c.next = h1;
        if (h2 != null) c.next = h2;
        
        return fake_head.next;
    }
}
