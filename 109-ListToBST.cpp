class Solution {
public:
	TreeNode* build(ListNode* head) {
		if(!head) return nullptr;
		if(!head->next) return new TreeNode(head->val);
		ListNode *p=head, *q=head, *pre=head;
		while(q && q->next) {
			pre = p;
			p = p->next;
			q = q->next->next;
		}
		TreeNode* node = new TreeNode(p->val);
		pre->next = nullptr;
		node->left = build(head);
		node->right = build(p->next);
		return node;
	}
	
	TreeNode* sortedListToBST(ListNode* head) {
		return build(head);		
	}
};

class Solution { //inorder
//references:https://leetcode.com/discuss/10924/share-my-code-with-o-n-time-and-o-1-space
public:
	ListNode* list;
	int sizeofList(ListNode* head) {
		int size=0;
		while(head) {
			++size;
			head = head->next;
		}
		return size;
	}

	TreeNode* generate(int n) {
		if(!n) return nullptr;
		TreeNode *node = new TreeNode(0);
		node->left = generate(n/2);
		node->val = list->val;
		list = list->next;
		node->right = generate(n-n/2-1);
		return node;
	}

	TreeNode* sortedListToBST(ListNode *head) {
		this->list = head;
		return generate(sizeofList(head));
	}
};
