class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(!root) return;
		TreeLinkNode *pre=root;
		TreeLinkNode *cur=nullptr;
		while(pre->left) {
			cur = pre;
			while(cur) {
				cur->left->next = cur->right;
				if(cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}
	}
};
