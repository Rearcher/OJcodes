// 629. K Inverse Pairs Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == n * (n - 1) / 2) return 1;
        if (k > n * (n - 1) / 2 || k < 0) return 0;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        int mod = pow(10, 9) + 7;

        dp[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i * (i - 1) / 2); ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j] + mod) % mod;
            }
        }

        return (int)dp[n][k];
    }
};

int main() {
    Solution s;
    cout << s.kInversePairs(1000, 1000) << endl;
}