class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p1 = headA;
		ListNode *p2 = headB;
		while(p1 && p2 && p1!=p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		if(p1 && p2) return p1;
		if(!p1 && !p2) return nullptr;

		if(!p1) {
			ListNode *p22 = headB;
			while(p2) {
				p2 = p2->next;
				p22 = p22->next;
			}
			p1 = headA;
			while(p1 && p22 && p1!=p22) {
				p1 = p1->next;
				p22 = p22->next;
			}
			if(p1) return p1;
			else return nullptr;
		}
		else if(!p2) {
			ListNode *p11 = headA;
			while(p1) {
				p1 = p1->next;
				p11 = p11->next;
			}
			p2 = headB;
			while(p11 && p2 && p11!=p2) {
				p11 = p11->next;
				p2 = p2->next; 
			}
			if(p11) return p11;
			else return nullptr;
		}
		return nullptr;
	}
};
