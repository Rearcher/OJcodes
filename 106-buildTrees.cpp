class Solution {
public:
	template<typename Iter>
	TreeNode* make(Iter is, Iter ie, Iter ps, Iter pe) {
		if(ps == pe) return nullptr;
		if(is == ie) return nullptr;
		int val = *(pe-1);
		auto iRoot = find(is, ie, val);
		TreeNode *root = new TreeNode(*iRoot);
		int leftSize = iRoot - is;
		root->left = make(is, iRoot, ps, ps+leftSize);
		root->right = make(iRoot+1, ie, ps+leftSize, pe-1);
		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.empty()) return nullptr;
		return make(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};
