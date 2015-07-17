class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> cur;
		if(root==nullptr) return ans;
		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);
		
		bool flag=false;
		while(!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if(t==nullptr) {
				if(flag) reverse(cur.begin(),cur.end());
				flag = !flag;
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
		return ans;
	}
};

