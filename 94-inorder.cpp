class Solution {//iterative solution
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode *> vis;
		TreeNode* cur = root;

		while(cur || !vis.empty()) {
			if(cur) {
				vis.push(cur);
				cur = cur->left;
			}
			else {
				cur = vis.top();
				vis.pop();
				ans.push_back(cur->val);
				cur = cur->right;
			}
		}
		return ans;
	}
};

class Solution {//Morris traversal
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode* cur = root;

		while(cur) {
			if(cur->left) {
				TreeNode* pre = cur->left;
				while(pre->right && pre->right!=cur)
					pre = pre->right;
				if(!(pre->right)) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}
			}
			else {
				ans.push_back(cur->val);
				cur = cur->right;
			}
		}
		return ans;
	}
};
