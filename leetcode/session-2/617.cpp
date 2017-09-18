// 617. Merge Two Binary Trees
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;

        int val = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
        TreeNode* node = new TreeNode(val);

        node->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        node->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);

        return node;
    }
};

int main() {

}