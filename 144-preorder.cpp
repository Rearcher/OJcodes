class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(!root) return ans;

		stack<TreeNode *> s;
		s.push(root);

		while(!s.empty()) {
			TreeNode *t = s.top();
			ans.push_back(t->val);
			s.pop();
			if(t->right) s.push(t->right);
			if(t->left) s.push(t->left);
		}
		return ans;
	}
};
