// 404. Sum of Left Leaves
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        traversal(root, result, false);
        return result;
    }

private:
    void traversal(TreeNode* root, int &result, bool is_left) {
        if (root == NULL) {
            return;
        }

        if (is_left && root->left == NULL && root->right == NULL) {
            result += root->val;
        }

        if (root->left) {
            traversal(root->left, result, true);
        }

        if (root->right) {
            traversal(root->right, result, false);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;
}