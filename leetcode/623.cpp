// 623. Add One Row to Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return new TreeNode(v);

        d -= 1;
        if (d == 0) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }

        vector<TreeNode*> level{root}, newLevel;
        while (d > 1) {
            d -= 1;
            for (TreeNode* node : level) {
                if (node->left) newLevel.push_back(node->left);
                if (node->right) newLevel.push_back(node->right);
            }

            level = vector<TreeNode*>(newLevel);
            newLevel.clear();
        }

        for (TreeNode* node : level) {
            TreeNode* originLeft = node->left;
            TreeNode* originRight = node->right;
            node->left = new TreeNode(v);
            node->right = new TreeNode(v);
            node->left->left = originLeft;
            node->right->right = originRight;
        }

        return root;
    }
};