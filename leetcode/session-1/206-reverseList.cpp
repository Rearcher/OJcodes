class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(head==nullptr) return head;
		ListNode *fake = new ListNode(0);
		fake->next = head;

		ListNode *p=head, *pre=fake, *mov;

		while(p->next) {
			mov = p->next;
			p->next = mov->next;
			mov->next = pre->next;
			pre->next = mov;
		}
		return fake->next;
	}
}
