// 637. Average of Levels in Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return vector<double>{};

        vector<TreeNode*> level{root}, snapshot;
        vector<double> result;

        while (!level.empty()) {
            snapshot.clear();
            long long sum = 0;

            for (TreeNode* node : level) {
                if (node->left) snapshot.push_back(node->left);
                if (node->right) snapshot.push_back(node->right);
                sum += node->val;
            }

            result.push_back(1.0 * sum / level.size());
            level = vector<TreeNode*>(snapshot);
        }

        return result;
    }
};

int main() {

}