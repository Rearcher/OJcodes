// 652. Find Duplicate Subtrees
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<string> exist, used;
        vector<TreeNode*> result;
        inorder(root, exist, used, result);
        
        return result;
    }

private:
    string inorder(TreeNode* root, unordered_set<string>& exist, unordered_set<string>& used, vector<TreeNode*>& result) {
        if (!root) return "";

        string left = inorder(root->left, exist, used, result);
        string right = inorder(root->right, exist, used, result);
        string all = "l" + left + "m" + to_string(root->val) + "r" + right;

        if (exist.count(all) && !used.count(all)) {
            result.push_back(root);
            used.insert(all);
        }
        exist.insert(all);
        
        return all;
    }
};

int main() {

}