// 543. Diameter of Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int result = 0;
        helper(root, result);
        return result;
    }

private:
    int helper(TreeNode* root, int& result) {
        if (!root->left && !root->right)
            return 0;
        
        int left_depth = 0, right_depth = 0;
        if (root->left) {
            left_depth = 1 + helper(root->left, result);
        }
        if (root->right) {
            right_depth = 1 + helper(root->right, result);
        }

        result = max(result, left_depth + right_depth);
        return max(left_depth, right_depth);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    cout << s.diameterOfBinaryTree(root) << endl;
}