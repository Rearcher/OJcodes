struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head==NULL || head->next==NULL) return head;	

		ListNode* p = head->next;
		head->next = p->next;
		p->next = head;
		head = p;

		p = p->next;
		while(p->next!=NULL) {
			ListNode* q = p->next;
			if(q->next==NULL) break;
			ListNode* r = q->next;
			
			q->next = r->next;
			r->next = p->next;
			p->next = r;
			
			p = q;
		}
		return head;
	}
};
