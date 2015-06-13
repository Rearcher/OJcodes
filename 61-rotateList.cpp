class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(head==NULL) return head;
		int len=1;
		ListNode* p=head, *q=head, *newhead;
		while(p->next) {
			len++;
			p = p->next;
		}
		p->next = head;		//make it a circle

		k %= len;
		for(int i=0; i<len-k-1; i++) q = q->next;
		newhead = q->next;
		q->next = NULL;
		return newhead;
	}
};
