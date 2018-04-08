// 814. Binary Tree Pruning
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        containOne(root);
        return root;
    }

private:
    bool containOne(TreeNode* node) {
        if (!node) return false;

        if (!node->left && !node->right && node->val == 0) {
            return false;
        }

        bool left = containOne(node->left);
        bool right = containOne(node->right);

        if (node->left && !left) {
            TreeNode* tmp = node->left;
            node->left = nullptr;
            free(node->left);
        }

        if (node->right && !right) {
            TreeNode* tmp = node->right;
            node->right = nullptr;
            free(node->right);
        }

        return left || right || node->val == 1;
    }
};