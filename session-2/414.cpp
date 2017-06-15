// 414. Third Maximum Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1, max2, max3;
        max1 = max2 = max3 = INT_MIN - 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3)
                continue;
            if (max1 == INT_MIN - 1 || nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (max2 == INT_MIN - 1 || nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if (max3 == INT_MIN - 1 || nums[i] > max3) {
                max3 = nums[i];
            }
        }

        return max3 == INT_MIN - 1 ? max1 : max3;
    }
};

int main() {
    Solution s;
    vector<int> nums{3, 2, 1};
    cout << s.thirdMax(nums) << endl;
}