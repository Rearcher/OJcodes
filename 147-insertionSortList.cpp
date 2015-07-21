class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if(!head) return head;
		ListNode *pre = head;
		ListNode *cur = head->next;
		while(cur) {
			if(cur->val >= pre->val) {
				pre = cur;
				cur = cur->next;
				continue;
			}

			pre->next = cur->next;
			ListNode *p = head;
			if(p->val >= cur->val) {
				cur->next = head;
				head = cur;
			}
			else {
				while(p!=pre && p->next->val<cur->val)
					p = p->next;
				cur->next = p->next;
				p->next = cur;
					
			}
			cur = pre->next;
		}
		
		return head;
	}
};
