class Solution {
public:
	vector<TreeNode*> generate(int s, int e) {
		vector<TreeNode*> subtree;
		if(s > e) {
			subtree.push_back(nullptr);
			return subtree;
		}
		for(int k=s; k<=e; k++) {
			vector<TreeNode*> left = generate(s,k-1);
			vector<TreeNode*> right = generate(k+1,e);
			for(auto i : left) {
				for(auto j : right) {
					TreeNode *node = new TreeNode(k);
					node->left = i;
					node->right = j;
					subtree.push_back(node);
				}
			}
		}
		return subtree;
	}
	
	vector<TreeNode*> generateTrees(int n) {
		if(n==0) return generate(1,0);
		return generate(1,n);
	}
};
