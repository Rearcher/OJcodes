/* binary tree inorder traversal */
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *pCurrent = root;
        
        while (!s.empty() || pCurrent) {
            if (pCurrent) {
                s.push(pCurrent);
                pCurrent = pCurrent->left;
            } else {
                TreeNode *p = s.top();
                s.pop();
                res.push_back(p->val);
                pCurrent = p->right;
            }
        }
        
        return res;
    }
};
