class Solution {
public:
	void dfs(TreeNode *root, int sum, int &ans) {
		if(!root) return;
		if(!root->left && !root->right) {
			sum = sum*10 + root->val;
			ans += sum;
			return;
		}
		dfs(root->left, sum*10+root->val, ans);
		dfs(root->right, sum*10+root->val, ans);
		return;
	}

	int sumNumbers(TreeNode *root) {
		int ans;
		dfs(root, 0, ans);
		return ans;
	}
};
