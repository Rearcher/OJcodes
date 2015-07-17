//references: http://www.cnblogs.com/x1957/p/3519452.html
class Solution {
public:
	template<typename Iter>
	TreeNode* make(Iter ps, Iter pe, Iter is, Iter ie) {
		if(ps == pe) return nullptr;
		if(is == ie) return nullptr;
		int val = *ps;
		auto iRoot = find(is, ie, val);
		TreeNode *root = new TreeNode(*iRoot);
		int leftSize = iRoot - is;
		root->left = make(ps+1, ps+leftSize+1, is, iRoot);
		root->right = make(ps+leftSize+1, pe, iRoot+1, ie);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.empty()) return nullptr;
		return make(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
