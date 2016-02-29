class Solution {
public:
	void dfs(TreeNode *root, int s, int sum, bool &ans) {
		if(!root) return;
		if(!root->left && !root->right) {
			if(s+root->val == sum) ans = true;
			return;
		}
		
		dfs(root->left, s+root->val, sum, ans);
		dfs(root->right, s+root->val, sum, ans);
		return;
	}

	bool hasPathSum(TreeNode *root, int sum) {
		bool ans = false;
		dfs(root, 0, sum, ans);
		return ans;
	}
};

class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if(root==nullptr) return false;
		if(root->val == sum && !root->left && !root->right) return true;
		return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
	}
};
