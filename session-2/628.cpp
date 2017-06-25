// 628. Maximum Product of Three Numbers
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) {
            return nums[0] * nums[1] * nums[2];
        }

        sort(nums.begin(), nums.end());
        int result = 0;
        if (nums[0] < 0 && nums[1] < 0) {
            result = max(nums[0] * nums[1] * nums[nums.size() - 1], 
                         nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
        } else {
            result = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        }

        return result;
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution s;
    cout << s.maximumProduct(nums) << endl;
}