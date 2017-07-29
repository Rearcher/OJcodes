// 209. Minimum Size Subarray Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, result = INT_MAX;

        while (end < nums.size()) {
            while (end < nums.size() && sum < s) sum += nums[end++];
            if (sum < s) break;
            
            while (start < end && sum >= s) sum -= nums[start++];
            result = min(result, end - start + 1);
        }

        return result == INT_MAX ? 0 : result;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 2, 4, 3};
    Solution s;
    cout << s.minSubArrayLen(7, nums) << endl;
}