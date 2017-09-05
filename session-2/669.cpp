// 669. Trim a Binary Search Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;

        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};