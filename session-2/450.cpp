// 450. Delete Node in a BST
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if  (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }

            TreeNode* tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution s;
    s.deleteNode(root, 3);
}