// 124. Binary Tree Maximum Path Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* node, int& result) {
        if (!node) return 0;

        int left = max(0, dfs(node->left, result));
        int right = max(0, dfs(node->right, result));
        result = max(result, left + right + node->val);

        return max(left, right) + node->val;
    }
};