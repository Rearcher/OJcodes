class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return ans;
	}
};


class Solution {
public:
	vector<vector<int>> ans;

	void buildVec(TreeNode *root, int depth) {
		if(root==nullptr) return;
		if(ans.size()==depth) ans.push_back(vector<int>());

		ans[depth].push_back(root->val);
		buildVec(root->left, depth+1);
		buildVec(root->right, depth+1);
	}

	vector<vector<int>> levelOrder(TreeNode *root) {
		buildVec(root,0);
		return ans;
	}


};
