// 494. Target Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum || S < -sum) return 0;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum * 2 + 1));
        dp[0][sum] = 1;

        // where dp[i][j] means the number of ways nums[0...i-1] can reach a sum j
        // so dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j < sum * 2 + 1; ++j) {
                if (j - nums[i-1] > 0) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
                if (j + nums[i-1] <= 2 * sum) {
                    dp[i][j] += dp[i-1][j+nums[i-1]];
                }
            }
        }

        return dp[nums.size()][sum+S];
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) return 0;
        
        unordered_map<string, int> m;
        return dfs(nums, S, 0, 0, m);
    }

private:
    int dfs(vector<int>& nums, int S, int index, int sum, unordered_map<string, int>& m) {
        string key = to_string(index) + "@" + to_string(sum);
        if (m.count(key)) {
            return m[key];
        }

        if (index == nums.size()) {
            return sum == S ? 1 : 0;
        }

        int add = dfs(nums, S, index + 1, sum + nums[index], m);
        int minus = dfs(nums, S, index + 1, sum - nums[index], m);
        m[key] = add + minus;

        return add + minus;
    }
};

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    Solution2 s;
    cout << s.findTargetSumWays(nums, 3) << endl;
}