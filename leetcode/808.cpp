// 808. Soup Services
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        vector<vector<double>> dp(200, vector<double>(200, 0));
        return N >= 4800 ? 1.0 : helper(dp, (N + 24) / 25, (N + 24) / 25);
    }

private:
    double helper(vector<vector<double>>& dp, int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;

        if (dp[a][b] > 0) return dp[a][b];
        dp[a][b] = 0.25 * (helper(dp, a - 4, b) + helper(dp, a - 3, b - 1) + 
                           helper(dp, a - 2, b - 2) + helper(dp, a - 1, b - 3));
        return dp[a][b];
    }
};

int main() {
    Solution s;
    for (int i = 0; i < 1000; ++i) {
        cout << i << ": " << s.soupServings(i) << "\n";
    }
}