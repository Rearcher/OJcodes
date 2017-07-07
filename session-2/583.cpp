// 583. Delete Operation for Two Strings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // dp[i][j] stands for the length of longest common subsequence of word1[0...i-1] and word2[0...j-1]
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (word1[i-1] == word2[j-1]) ? (dp[i-1][j-1] + 1) : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return m + n - 2 * dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("sea", "eat") << endl;
}