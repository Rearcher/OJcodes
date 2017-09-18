/**
 * Partition List
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smallerHead = new ListNode(0);
        ListNode largerHead = new ListNode(0);
        ListNode curNode = head, curSmall = smallerHead, curLarge = largerHead;
        
        while (curNode != null) {
            if (curNode.val < x) {
                curSmall.next = curNode;
                curNode = curNode.next;
                curSmall = curSmall.next;
                curSmall.next = null;
            } else {
                curLarge.next = curNode;
                curNode = curNode.next;
                curLarge = curLarge.next;
                curLarge.next = null;
            }
        }
        
        curSmall.next = largerHead.next;
        return smallerHead.next;
    }
}
