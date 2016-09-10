/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
    
        PriorityQueue<ListNode> heap = new PriorityQueue<>((a, b) -> a.val - b.val);

        for (int i = 0; i < lists.length; ++i) {
            ListNode cur = lists[i];         
            if (cur != null) heap.offer(cur);
        }

        ListNode fakeHead = new ListNode(0);
        ListNode cur = fakeHead;
        while (heap.size() > 0) {
            ListNode temp = heap.poll();
            if (temp.next != null)
                heap.offer(temp.next);
            temp.next = null;
            cur.next = temp;
            cur = cur.next;
        }

        return fakeHead.next;
    }
}
