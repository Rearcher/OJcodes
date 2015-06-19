class Solution {
public:
	void search(TreeNode* root, int& depth, int &max) {
		if(root==NULL) return;
		if(max<depth) max=depth;
		if(root->left==NULL && root->right==NULL) return;
		if(root->left) {
			search(root->left, ++depth, max);
			depth--;
		}
		if(root->right) {
			search(root->right, ++depth, max);
			depth--;
		}
	}

	int maxDepth(TreeNode* root) {
		if(root==NULL) return 0;
		int depth=1,ans=0;
		search(root,depth,ans);
		return ans;
	}
	
};
