/* lowest common ancestor in a binary tree */
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
	/* recursive */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : (!right ? left : root);
    }
	
	/* iterative, based on path comparing */
	TreeNode* lowestCommonAncestor_ex(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        vector<TreeNode*> pathP, pathQ;
        vector<TreeNode*> pathTemp;
        
		/* prev is used to mark the node visited last time */
        TreeNode *prev = nullptr, *pNode;
        pathTemp.push_back(root);
        
        while (pathP.empty() || pathQ.empty()) {
            pNode = pathTemp.back();
            if (pNode == p) pathP = pathTemp;
            if (pNode == q) pathQ = pathTemp;
			
			/* Three conditions you need to pop back
			 * 1. current node has no sons
			 * 2. current node has only left son, and it has been visited
			 * 3. current node has only right son, and it has been visited
			 */ 
            if ((!pNode->left && !pNode->right) || (!pNode->right && prev == pNode->left) || 
            (pNode->right && prev == pNode->right)) {
                pathTemp.pop_back();
                prev = pNode;
            } else {
				/* if current node has no left son or its left son has been visited,
				 * go right, else push left son
				 */
                if (!pNode->left || prev == pNode->left) {
                    pathTemp.push_back(pNode->right);
                } else {
                    pathTemp.push_back(pNode->left);
                }
            }
        }
        
        unsigned int i;
        for (i = 1; i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]; ++i);
        return pathP[i-1];
    }
};
