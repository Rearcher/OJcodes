// #medium
// #BST
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root, *prev = nullptr;
        bool left = true;
        while (cur) {
            prev = cur;
            if (val < cur->val) {
                cur = cur->left;
                left = true;
            } else {
                cur = cur->right;
                left = false;
            }
        }
        
        if (prev == nullptr) return new TreeNode(val);
    
        if (left) prev->left = new TreeNode(val);
        else prev->right = new TreeNode(val);    
        return root;
    }
};