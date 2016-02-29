class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(!root) return ans;

		stack<TreeNode *> s;
		stack<int> flag;

		s.push(root);
		flag.push(0);
		while(!s.empty()) {
			TreeNode *t = s.top();
			int old_flag = flag.top();
			int new_flag = 0;
			
			if(old_flag) {
				ans.push_back(t->val);
				s.pop(); flag.pop();
				continue;
			}

			if(!t->left && !t->right) {
				ans.push_back(t->val);
				s.pop(); flag.pop();
				continue;
			}
			
			new_flag = 1;
			flag.pop();
			flag.push(new_flag);

			if(t->right) { 
				s.push(t->right);
				flag.push(0);
			}
			if(t->left) {
				s.push(t->left);
				flag.push(0);
			}
		}
		return ans;
	}
};


	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(!root) return ans;

		stack<TreeNode *> s;
		TreeNode *lastNode = nullptr;
		TreeNode *cur = root;
		
		while(cur || !s.empty()) {
			if(cur) {
				s.push(cur);
				cur = cur->left;
			}
			else {
				TreeNode *t = s.top();
				if(t->right && lastNode!=t->right)
					cur = t->right;
				else {
					ans.push_back(t->val);
					lastNode = t;
					s.pop();
				}
			}
		}

		return ans;
	}
