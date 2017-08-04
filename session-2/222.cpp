// 222. Count Complete TreeNodes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        TreeNode *left = root, *right = root;
        int height = 0;
        while (right) {
            left = left->left;
            right = right->right;
            height += 1;
        }

        if (!left) return (1 << height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {

}