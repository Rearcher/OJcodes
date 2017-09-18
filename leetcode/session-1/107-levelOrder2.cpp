class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> cur;
		if(root==nullptr) return ans;
		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);

		while(!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if(t==nullptr) {
				ans.push_back(cur);
				cur.resize(0);
				if(q.size()>0) q.push(nullptr);
			}
			else {
				cur.push_back(t->val);
				if(t->left) q.push(t->left);
				if(t->right) q.push(t->right);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


