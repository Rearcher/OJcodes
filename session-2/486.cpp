// 486. Predict the Winner
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j] means in nums[i...j], the first-action-player can earn how much more scores than the other

        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];

        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }

        return dp[0][n-1] >= 0;
    }
};

int main() {

}