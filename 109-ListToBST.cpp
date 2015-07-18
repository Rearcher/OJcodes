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
