struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode root(0);
		ListNode* p = &root;

		while(l1 && l2) {
			if(l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = p?p:q;
		return root.next;
	}
	
	ListNode* mergeKLists(vector<ListNode*>& Lists) {
		int n=Lists.size();
		if(n==0) return NULL;
		else if(n==1) return Lists[0];
		//Bottom-up recursion	
		vector<ListNode*> ans;
		while(!Lists.empty()) {
			if(Lists.size()==1) {
				ans.push_back(Lists.back());
				Lists.pop_back();
			}
			else {
				ListNode *p = Lists.back();
				Lists.pop_back();
				ListNode *q = Lists.back();
				Lists.pop_back();
				ans.push_back(mergeTwoLists(p,q));
			}
		}
		return mergeKLists(ans);
	}
};
