/* lowest common ancestor in binary search tree */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *pNode = root;
        while (true) {
            if (p->val < pNode->val && q->val < pNode->val)
                pNode = pNode->left;
            else if (p->val > pNode->val && q->val > pNode->val)
                pNode = pNode->right;
            else return pNode;
        }
    }
};
