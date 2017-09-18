#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> genTrees(int start, int end) {
		vector<TreeNode *> res;

		if (start > end) {
			return res;
		}

		if (start == end) {
			res.push_back(new TreeNode(start));
			return res;
		}

		vector<TreeNode *> left, right;
		for (int i = start; i <= end; ++i) {
			left = genTrees(start, i - 1);
			right = genTrees(i + 1, end);

			for (TreeNode *leftNode : left) {
				for (TreeNode *rightNode : right) {
					TreeNode *root = new TreeNode(i);
					root->left = leftNode;
					root->right = rightNode;
					res.push_back(root);
				}
			}
		}

		return res;
	}
	
	vector<TreeNode *> generateTrees(int n) {
		if (n == 0) return vector<TreeNode *>();
		return genTrees(1, n);
	}
};

int main() {

}
