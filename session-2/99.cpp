// 99. Recover Binary Search Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        first = second = nullptr;
        prev = new TreeNode(INT_MIN);
        traverse(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

private:
    TreeNode *first, *second, *prev;

    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);

        if (first == nullptr && prev->val >= root->val)
            first = prev;
        if (first != nullptr && prev->val >= root->val)
            second = root;
        prev = root;

        traverse(root->right);
    }
};