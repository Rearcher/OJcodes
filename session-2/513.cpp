// 513. Find Bottom Left Tree Value
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;

        vector<TreeNode*> level{root}, new_level;
        int result = level[0]->val;

        while (!level.empty()) {
            result = level[0]->val;

            for (auto node : level) {
                if (!node) 
                    continue;
                if (node->left) 
                    new_level.push_back(node->left);
                if (node->right) 
                    new_level.push_back(node->right);
            }

            level = vector<TreeNode*>(new_level);
            new_level.clear();
        }

        return result;
    }
};

int main() {

}