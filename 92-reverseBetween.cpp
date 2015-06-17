class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* pre = newhead;
		for(int i=0; i<m-1; i++)
			pre = pre->next;
		ListNode* cur = pre->next;
		for(int i=0; i<n-m; i++) {
			ListNode* move = cur->next;
			cur->next = move->next;
			move->next = pre->next;
			pre->next = move;
		}
		return newhead->next;
	}

};
