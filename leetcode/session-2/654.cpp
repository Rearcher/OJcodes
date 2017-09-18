// 654. Maximum Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;
        if (begin == end) return new TreeNode(nums[begin]);

        int maxNum = INT_MIN, maxIndex = -1;
        for (int i = begin; i <= end; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        }

        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = helper(nums, begin, maxIndex - 1);
        root->right = helper(nums, maxIndex + 1, end);

        return root;
    }
};

int main() {

}