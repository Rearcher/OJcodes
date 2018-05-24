// 837. New 21 Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N >= K + W - 1) return 1.0;

        vector<double> dp(K + W, 0);
        double prob = 1.0 / W, prev = 0;
        dp[0] = 1;

        for (int i = 1; i <= K; ++i) {
            prev = prev - (i - W - 1 >= 0 ? dp[i - W - 1] : 0) + dp[i - 1];
            dp[i] = prev * prob;
        }

        double res = dp[K];
        for (int i = K + 1; i <= N; ++i) {
            prev -= (i - W - 1 >= 0 ? dp[i - W - 1] : 0);
            dp[i] = prev * prob;
            res += dp[i];
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.new21Game(21, 17, 10) << endl;
}