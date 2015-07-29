class Solution {
public:
	TreeNode *invertTree(TreeNode *root) {
		if(!root || (!root->left && !root->right)) return root;
		TreeNode *t = root->left;
		root->left = root->right;
		root->right = t;
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		return root;
	}
};
