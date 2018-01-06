// 515. Find Largest Value in Each Tree Row
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        vector<TreeNode*> level{root}, new_level;
        while (level.size() > 0) {
            int m = level[0]->val;
            for (int i = 0; i < level.size(); ++i) {
                if (level[i]->left) 
                    new_level.push_back(level[i]->left);
                if (level[i]->right) 
                    new_level.push_back(level[i]->right);
                if (i > 0)
                    m = max(m, level[i]->val);
            }
            result.push_back(m);
            level = vector<TreeNode*> (new_level);
            new_level.clear();
        }

        return result;
    }
};

int main() {

}