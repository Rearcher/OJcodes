// 416. Partition Equal Subset Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;

        sum /= 2;
        // dp[i][j] means the first i elements in nums whether can sum to j or not
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        dp[0][0] = true;

        for (int i = 1; i < nums.size() + 1; ++i)
            dp[i][0] = true;
        for (int j = 1; j < sum + 1; ++j)
            dp[0][j] = false;

        for (int i = 1; i < nums.size() + 1; ++i) {
            for (int j = 1; j < sum + 1; ++j) {
                dp[i][j] = dp[i-1][j];
                if (nums[i-1] <= j) {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }

        return dp[nums.size()][sum];
    }
};

int main() {
    vector<int> nums{1, 2, 3, 5};
    Solution s;
    cout << s.canPartition(nums) << endl;
}