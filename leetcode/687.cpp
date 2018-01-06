// 687. Longest Univalue Path
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* cur, int& result) {
        if (cur == nullptr) return 0;

        int left = dfs(cur->left, result), right = dfs(cur->right, result);
        int leftCnt = 0, rightCnt = 0;
        if (cur->left && cur->left->val == cur->val)
            leftCnt += left + 1;
        if (cur->right && cur->right->val == cur->val)
            rightCnt += right + 1;
        result = max(result, leftCnt + rightCnt);

        return max(leftCnt, rightCnt);
    }
};