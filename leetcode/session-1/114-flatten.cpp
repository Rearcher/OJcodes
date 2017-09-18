//references:http://www.2cto.com/kf/201409/331296.html
class Solution {
public:
	void flatten(TreeNode *root) {
		if(!root) return;
		while(root) {
			if(root->left) {
				TreeNode *p = root->left;
				while(p->right) p = p->right;
				p->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
		return;
	}

};

class Solution {
public:
	TreeNode *pre=nullptr;
	void flatten(TreeNode *root) {
		if(!root) return;
		TreeNode *lastRight = root->right;
		if(pre) {
			pre->left = nullptr;
			pre->right = root;
		}
		pre = root;
		flatten(root->left);
		flatten(lastRight);
	}
};
