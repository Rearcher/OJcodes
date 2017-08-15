// 514. Freedom Trail
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();

        // dp[i][j] means the minimum steps to spell key.substr(i) with ring starts at index j
        vector<vector<int>> dp(m + 1, vector<int>(n));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (ring[k] != key[i]) continue;
                    int dist = abs(j - k);
                    dist = min(dist, n - dist);

                    // from dp[i+1][k] to dp[i][j], we should rotate ring from index k to j, which is denoted as "dist"
                    // so dp[i][j] = "dist" + dp[i+1][k]
                    dp[i][j] = min(dp[i][j], dist + dp[i+1][k]);
                }
            }
        }

        return dp[0][0] + m;
    }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("godding", "gd") << endl;
}