// 655. Print Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int d = depth(root);
        int w = (1 << d) - 1;

        vector<vector<string>> result(d, vector<string>(w, ""));
        helper(result, 0, w - 1, 0, root);

        return result;
    }

private:
    int depth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    void helper(vector<vector<string>>& result, int begin, int end, int depth, TreeNode* node) {
        result[depth][begin + (end - begin) / 2] = to_string(node->val);
        if (node->left) helper(result, begin, begin + (end - begin) / 2 - 1, depth + 1, node->left);
        if (node->right) helper(result, begin + (end - begin) / 2 + 1, end, depth + 1, node->right);
    }
};

int main() {

}