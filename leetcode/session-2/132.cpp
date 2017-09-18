// 132. Palindrome Partitioning II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j + 1 > i - 1 || isPal[j+1][i-1])) {
                    isPal[j][i] = true;
                    dp[i] = (j == 0 ? 0 : min(dp[i], dp[j-1] + 1));
                }
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution s;
    cout << s.minCut("abbab");
}