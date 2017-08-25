// 664. Strange Printer
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                dp[j][j+i] = i + 1;
                for (int k = j + 1; k <= j + i; ++k) {
                    int temp = dp[j][k-1] + dp[k][j+i];
                    if (s[k-1] == s[j+i]) temp--;
                    dp[j][j+i] = min(dp[j][j+i], temp);
                }
            }
        }

        return dp[0][n-1];
    }
};

int main() {
    Solution s;
    cout << s.strangePrinter("aaabbb") << endl;
} 