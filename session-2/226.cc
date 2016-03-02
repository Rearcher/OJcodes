class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *temp = root->left;
        
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }

	TreeNode *invertTree(TreeNode *root) {
		std::queue<TreeNode*> nodeQueue;
		if (root) nodeQueue.push(root);

		while (!nodeQueue.empty()) {
			TreeNode *curNode = nodeQueue.front();
			nodeQueue.pop();

			TreeNode *temp = curNode->left;
			curNode->left = curNode->right;
			curNode->right = temp;

			if (curNode->left) nodeQueue.push(curNode->left);
			if (curNode->right) nodeQueue.push(curNode->right);
		}
		return root;
	}
};
