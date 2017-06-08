// 437. Path Sum III
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, 0, sum, m);
    }

private:
    int helper(TreeNode* root, int curSum, int target, unordered_map<int, int>& m) {
        if (root == NULL) {
            return 0;
        }

        curSum += root->val;
        if (m.find(curSum) == m.end()) {
            m[curSum] = 1;
        } else {
            m[curSum] += 1;
        }

        int result = m.find(curSum - target) == m.end() ? 0 : m[curSum - target];

        if (target == 0) {  // special occasion
            result -= 1;
        }

        result += helper(root->left, curSum, target, m) + helper(root->right, curSum, target, m);
        m[curSum] -= 1; // important!

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    /*
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    */
    Solution s;
    cout << s.pathSum(root, 0) << endl;
}