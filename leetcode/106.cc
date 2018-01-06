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
	TreeNode* make(Iter inorderStart, Iter inorderEnd, Iter postorderStart, Iter postorderEnd) {
		if (inorderStart == inorderEnd) return nullptr;
		if (postorderStart == postorderEnd) return nullptr;
		
		int val = *(postorderEnd - 1);
		auto rootIter = find(inorderStart, inorderEnd, val);
		TreeNode *root = new TreeNode(*rootIter);
		int leftSize = rootIter - inorderStart;

		root->left = make(inorderStart, rootIter, postorderStart, postorderStart+leftSize);
		root->right = make(rootIter+1, inorderEnd, postorderStart+leftSize, postorderEnd-1);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty()) return nullptr;
		return make(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};

int main() {
	new Solution();
}
