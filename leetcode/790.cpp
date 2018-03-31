// 790. Domino and Tromino Tiling
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        if (N == 0) return 0;
        int mod = 1e9 + 7;

        vector<long long> dp(1001, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= N; ++i) {
            dp[i] = dp[i - 1] * 2 + dp[i - 3];
            dp[i] %= mod;
        }
        return dp[N];
    }
};

int main() {
    Solution s;
    cout << s.numTilings(1000) << "\n";
}