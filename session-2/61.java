/**
 * 61. Rotate List
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode fast = head, slow = head;
        ListNode fastPrev = null, slowPrev = null;
        int len = 0;
        while (fast != null) {
            fast = fast.next;
            len += 1;
        }
        fast = head;
        
        if (len > 0) k %= len;
        if (head == null || k == 0 || k == len)
            return head;

        for (int i = 0; i < k; ++i, fastPrev = fast, fast = fast.next);
        while (fast != null) {
            slowPrev = slow;
            slow = slow.next;
            
            fastPrev = fast;
            fast = fast.next;
        }
        
        slowPrev.next = null;
        fastPrev.next = head;
        return slow;
    }
}
