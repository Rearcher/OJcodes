struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len=0;
		ListNode* p = head;
		while(p!=NULL) {
			p = (*p).next;
			len++;
		}					//to know the length

		p = head;
		int pos=len-n-1;
		
		if(pos < 0) {
			head = (*head).next;
			delete p;
			return head;
		}

		for(int i = 0; i < pos; i++)
			p = (*p).next;

		ListNode* q = (*p).next;
		(*p).next = (*q).next;
		(*q).next = NULL;

		delete q;

		return head;
	}
}

//An easier way, learned from discuss, use two pointers
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* p = head;
		ListNode** pp = &head;
		while(n--) p = p->next;
		while(p) {
			p = p->next;
			pp = &(*pp)->next;
		}
		p = *pp;
		*pp = p->next;
		free(p);
		return head;
	}
}
