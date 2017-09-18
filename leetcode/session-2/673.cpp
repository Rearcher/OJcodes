// 673. Number of Longest Increasing Subsequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<pair<int, int>> dp(n);
        dp[0] = {1, 1};

        int maxLen = 1, maxCnt = 1;
        for (int i = 1; i < n; ++i) {
            int curMax = 0, curCnt = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j]) continue;
                if (dp[j].first > curMax) {
                    curMax = dp[j].first;
                    curCnt = dp[j].second;
                } else if (dp[j].first == curMax) {
                    curCnt += dp[j].second;
                }
            }

            if (curMax == 0) dp[i] = {1, 1};
            else dp[i] = {curMax + 1, curCnt};

            if (dp[i].first > maxLen) {
                maxLen = dp[i].first;
                maxCnt = dp[i].second;
            } else if (dp[i].first == maxLen) {
                maxCnt += dp[i].second;
            }
        }

        return maxCnt;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 1, 1, 1};
    cout << s.findNumberOfLIS(nums) << endl;
}