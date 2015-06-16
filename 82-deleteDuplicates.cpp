class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* fakeHead = new ListNode(INT_MIN);
		ListNode* q=fakeHead, *p=head;
		fakeHead->next = head;
	
		while(p && p->next) {
			if(p->next->val!=p->val) {
				q = p;
				p = p->next;
			}
			else {
				int val=p->val;
				while(p && p->val==val) {
					ListNode* t = p->next;
					q->next = t;
					delete p;
					p = t;
				}
			}
		}
		return fakeHead->next;
	}
}
