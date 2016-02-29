class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* p = head->next, *q = head;
		while(p) {
			if(p->val!=q->val) {
				q = p;
				p = p->next;
			}
			else {
				ListNode* t = p;
				p = p->next;
				q->next = p;
				delete t;
			}
		}
		return head;
	}
};
