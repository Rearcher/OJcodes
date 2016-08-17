/**
 * Reverse Nodes in k-Group
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode[] reverse(ListNode head) {
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        return new ListNode[]{pre, head};
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode cur = head;
        ListNode newHead = null, newTail = null;
        ListNode curHead = head, lastHead = null;
        while (cur != null) {
            int i = 1;
            while (cur != null && i < k) {
                cur = cur.next;
                i++;
            }
            if (i == k && cur != null) {
                lastHead = curHead;
                curHead = cur.next;
                cur.next = null;
                cur = curHead;

                ListNode[] temp = reverse(lastHead);
                if (newHead == null) newHead = temp[0];
                if (newTail != null) newTail.next = temp[0];
                newTail = temp[1];
            } else {
                if (newHead == null) return head;
                newTail.next = curHead;
            }
        }
        return newHead;
    }
}
