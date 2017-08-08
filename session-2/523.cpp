// 523. Continuous Subarray Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k) sum %= k;

            if (map.count(sum)) {
                if (i - map[sum] > 1)
                    return true;
            } else {
                map[sum] = i;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{0, 0};
    cout << s.checkSubarraySum(nums, 0);
}