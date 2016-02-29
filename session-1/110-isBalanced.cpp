class Solution {
public:
	int depth(TreeNode* root) {
		if(root==nullptr) return 0;
		return max(depth(root->left),depth(root->right))+1;
	}

	bool isBalanced(TreeNode *root) {
		if(root==nullptr) return true;
		int left = depth(root->left);
		int right = depth(root->right);
		return abs(left-right)<2 && isBalanced(root->left) && isBalanced(root->right);
	}
};

class Solution {
public:
	int dfs(TreeNode *root) {
		if(root==nullptr) return 0;

		int left = dfs(root->left);
		if(left == -1) return -1;
		int right = dfs(root->right);
		if(right == -1) return -1;
		
		if(abs(left-right)>1) return -1;
		return max(left,right)+1;
	}

	bool isBalanced(TreeNode *root) {
		return dfs(root)!=-1;
	}
};
