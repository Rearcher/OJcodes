// 516. Longest Palindromic Subsequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;

        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        // for (int i = len - 1; i >= 0; --i) {
        //     dp[i][i] = 1;
        //     for (int j = i + 1; j < len; ++j) {
        //         if (s[i] == s[j]) {
        //             dp[i][j] = dp[i+1][j-1] + 2;
        //         } else {
        //             dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;

        for (int interval = 2; interval <= len; ++interval) {
            for (int i = 0; i + interval <= len; ++i) {
                int j = i + interval - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][len-1];
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("bbabb") << endl;
}