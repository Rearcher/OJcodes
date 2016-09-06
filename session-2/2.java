/**
 * 2. Add Two Numbers
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode fakeHead = new ListNode(0);
        ListNode cur = fakeHead, cur1 = l1, cur2 = l2;
        int carry = 0;
        
        while (cur1 != null && cur2 != null) {
            int num = cur1.val + cur2.val + carry;
            carry = num / 10;
            num = num % 10;
            
            cur.next = new ListNode(num);
            cur = cur.next;
            cur1 = cur1.next;
            cur2 = cur2.next;
        }
        
        cur1 = (cur1 == null) ? cur2 : cur1;
        while (cur1 != null) {
            int num = cur1.val + carry;
            carry = num / 10;
            num = num % 10;
            
            cur.next = new ListNode(num);
            cur = cur.next;
            cur1 = cur1.next;
        }
        
        if (carry > 0) cur.next = new ListNode(carry);
        
        return fakeHead.next;
    }
}
