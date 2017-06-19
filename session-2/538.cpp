// 538. Convert BST to Greater Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        
        vector<int> vals;
        stack<TreeNode*> s;
        TreeNode* current = root;
        int sum = 0;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->right;
            } else {
                TreeNode* tmp = s.top();
                s.pop();
                tmp->val += sum;
                sum = tmp->val;
                current = tmp->left;
            }
        }

        return root;
    }
};

int main() {

}