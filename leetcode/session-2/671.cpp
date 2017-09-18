// 671. Second Minimum Node in a Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* p, int val) {
        if (p == nullptr) return -1;
        if (p->val != val) return p->val;

        int left = dfs(p->left, val);
        int right = dfs(p->right, val);

        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};