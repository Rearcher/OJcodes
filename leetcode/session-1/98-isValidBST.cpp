class Solution {
public:
	bool valid(TreeNode* node, TreeNode* &prev) {
		if(node==nullptr) return true;
		if(!valid(node->left, prev)) return false;
		if(prev!=nullptr && prev->val >= node->val) return false;
		prev = node;
		return valid(node->right, prev);
	}

	bool isValidBST(TreeNode* root) {
		TreeNode* prev = nullptr;
		return valid(root, prev);
	}
};
