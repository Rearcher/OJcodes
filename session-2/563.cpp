// 563. Binary Tree Tilt
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int res = 0;
        postOrder(root, res);
        
        return res;
    }

private:
    int postOrder(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }

        int left = postOrder(root->left, res);
        int right = postOrder(root->right, res);
        res += abs(left - right);

        return left + right + root->val;
    }
};

int main() {
}