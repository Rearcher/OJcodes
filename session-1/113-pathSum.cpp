class Solution {
public:
	void dfs(TreeNode *root, int sum, int s, vector<vector<int>> &ans, vector<int> cur) {
		if(!root) return;
		if(!root->left && !root->right) {
			if(s+root->val==sum) {
				cur.push_back(root->val);
				ans.push_back(cur);
				cur.resize(0);
			}
		}
		cur.push_back(root->val);
		dfs(root->left,sum,s+root->val,ans,cur);
		dfs(root->right,sum,s+root->val,ans,cur);
		cur.pop_back();
		return;
	}
	
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<vector<int>> ans;
		dfs(root,sum,0,ans,vector<int>());
		return ans;
	}
};
