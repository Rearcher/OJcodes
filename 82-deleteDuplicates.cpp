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

//Solution2, pointer of pointer
ListNode* deleteDuplicates(ListNode* head) {
	ListNode **runner = &head;
	if(!head || !head->next) return head;
	while(*runner) {
		if((*runner)->next && (*runner)->next->val==(*runner)->val)
		{
			ListNode *t = *runner;
			while(t && t->val==(*runner)->val)
				t = t->next;
			*runner = t;
		}
		else
			runner = &((*runner)->next);
	}
	return head;
}
