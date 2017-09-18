/**
 * Intersection of Two Linked Lists
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p1 = headA, p2 = headB;
        while (p1 != null && p2 != null && p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }

        if (p1 != null && p2 != null) {
            return p1;
        } else if (p1 == null && p2 != null) {
            ListNode oldP2 = p2;
            p2 = headB; p1 = headA;
            while (oldP2 != null) {
                oldP2 = oldP2.next;
                p2 = p2.next;
            }
        } else if (p1 != null && p2 == null) {
            ListNode oldP1 = p1;
            p1 = headA; p2 = headB;
            while (oldP1 != null) {
                oldP1 = oldP1.next;
                p1 = p1.next;
            }
        } else {
            return null;
        }

        while (p1 != null && p2 != null && p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }
        if (p1 != null && p2 != null && p1 == p2) {
            return p1;
        }
        return null;
    }
}
