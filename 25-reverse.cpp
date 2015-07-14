class Solution {
public:
	ListNode* reverseKNodes(ListNode* head, int k) {
		ListNode* fake = new ListNode(0);
		fake->next = head;
		ListNode* cur = head, *pre = fake;
		for(int i=1; i<k; i++) {
			ListNode* nex = cur->next;

			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
		}
		return fake->next;
	}
	
	ListNode* moveKNodes(ListNode *head, int k) {
		ListNode *p = head;
		for(int i=1; i<k; i++)  p = p->next;
		return p;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		if(head==nullptr) return head;
		int len=0;
		ListNode* p = head;
		while(p) {
			len++; p = p->next;
		}
		if(len<k) return head;
		head = reverseKNodes(head, k);
		p = moveKNodes(head, k);
		for(int i=0; i<len/k-1; i++) {
			p->next = reverseKNodes(p->next, k);
			p = moveKNodes(p->next, k);
		}
		return head;
	}
}
