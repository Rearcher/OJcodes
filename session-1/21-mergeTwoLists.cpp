struct ListNode {
i	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head;
		
		if(l1==NULL && l2==NULL) return NULL;
		else if(l1==NULL) return l2;
		else if(l2==NULL) return l1;

		if(l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}
		ListNode* p = head;

		while(l1!=NULL && l2!=NULL) {
			if(l1->val < l2->val) {
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}

		while(l1!=NULL) {
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}

		while(l2!=NULL) {
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}

		return head;
	}
};

//Another solution learned from discuss
class Solution {
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode root(0);
		root.next = l1;
		ListNode* p = &root;
		while(l2) {
			while(p->next && p->next->val<=l2->val) p = p->next;
			l1 = p->next;
			p->next = l2;
			l2 = l1;
		}
		return root.next;
	}
}
