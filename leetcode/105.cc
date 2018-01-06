#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	template<typename Iter>
	TreeNode* make(Iter preorderStart, Iter preorderEnd, Iter inorderStart, Iter inorderEnd) {
		if (preorderStart == preorderEnd) return nullptr;
		if (inorderStart == inorderEnd) return nullptr;

		int val = *preorderStart;
		auto rootIter = find(inorderStart, inorderEnd, val);
		TreeNode *root = new TreeNode(*rootIter);
		
		int leftSize = rootIter - inorderStart;
		root->left = make(preorderStart+1, preorderStart+leftSize+1, inorderStart, rootIter);
		root->right = make(preorderStart+leftSize+1, preorderEnd, rootIter+1, inorderEnd);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return nullptr;
		return make(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};

int main() {
	vector<int> preorder = {1, 2, 4, 5, 3};
	vector<int> inorder = {4, 2, 5, 1, 3};

	TreeNode *root = (new Solution())->buildTree(preorder, inorder);
}
