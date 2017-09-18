// 665. Non-decreasing Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modified = 0;

        for (int i = 1; i < nums.size() && modified <= 1; ++i) {
            if (nums[i-1] > nums[i]) {
                modified += 1;
                if (i - 2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }

        return modified <= 1;
    }
};

int main() {
    Solution s;
    vector<int> nums{4, 2, 3};
    cout << s.checkPossibility(nums) << endl;
}