class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while(head && head->val==val) head = head->next;
		if(head==NULL) return head;
			
		ListNode *pre=head, *q=pre->next;;

		while(q) {
			if(q->val==val) {
				ListNode *t = q;
				q = q->next;
				pre->next = q;
				delete t;
			}
			else {
				q = q->next;
				pre = pre->next;
			}
		}
		return head;
	}
}
