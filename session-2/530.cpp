// 530. Minimum Absolute Difference in BST
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        stack<TreeNode*> s;
        vector<int> vals;

        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            vals.push_back(tmp->val);
            if (tmp->right) {
                s.push(tmp->right);
            }
            if (tmp->left) {
                s.push(tmp->left);
            }
        }

        sort(vals.begin(), vals.end());
        int result = INT_MAX;
        for (int i = 0; i < vals.size() - 1; ++i) {
            result = min(result, vals[i+1] - vals[i]);
        }

        return result;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    cout << s.getMinimumDifference(root) << endl;
}