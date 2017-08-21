// 663. Equal Tree Partition
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return false;

        unordered_set<int> cache;
        int sum = helper(root, cache);
        if (sum % 2 || !cache.count(sum / 2)) return false;

        return true;
    }

private:
    int helper(TreeNode* root, unordered_set<int>& cache) {
        if (!root) return 0;

        int left = helper(root->left, cache);
        int right = helper(root->right, cache);
        int sum = left + right + root->val;
        cache.insert(sum);

        return sum;
    }
};

