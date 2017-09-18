class Solution {
public:
	bool judge(TreeNode* root1, TreeNode* root2) {
		if(root1==nullptr && root2==nullptr) return true;
		if(root1==nullptr || root2==nullptr) return false;
		if(root1->val != root2->val) return false;
		return judge(root1->left, root2->right)&&judge(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		if(root==nullptr) return true;
		return judge(root->left, root->right);
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(root==nullptr) return true;
		stack<TreeNode*> s;
		s.push(root->left);
		s.push(root->right);

		TreeNode *a, *b;
		while(!s.empty()) {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();

			if(!a && !b) continue;
			if(!a || !b) return false;
			if(a->val != b->val) return false;

			s.push(a->left);
			s.push(b->right);
			s.push(a->right);
			s.push(b->left);
		}
		return true;
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(root==nullptr) return true;
		queue<TreeNode*> q1, q2;
		q1.push(root->left);
		q2.push(root->right);

		TreeNode *a, *b;
		while(!q1.empty() && !q2.empty()) {
			a = q1.front(); q1.pop();
			b = q2.front(); q2.pop();
			if(!a && !b) continue;
			if(!a || !b) return false;
			if(a->val != b->val) return false;
			q1.push(a->left);
			q2.push(b->right);
			q1.push(a->right);
			q2.push(b->left);
		}
		return true;
	}
};
