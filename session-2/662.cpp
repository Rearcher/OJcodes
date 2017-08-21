// 662. Maximum Width of Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        int result = 0;
        dfs(root, 1, 0, lefts, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int id, int level, vector<int>& lefts, int& result) {
        if (!root) return;
        if (level >= lefts.size()) lefts.push_back(id);
        result = max(result, id - lefts[level] + 1);

        dfs(root->left, id * 2, level + 1, lefts, result);
        dfs(root->right, id * 2 + 1, level + 1, lefts, result);
    }
}