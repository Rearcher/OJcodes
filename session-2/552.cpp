// 552. Student Attendance Record II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        // dp[i][j][k] means valid sequence of length i, with at most j As and at most k trailing Ls
        int dp[n+1][2][3], mod = 1000000007;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                dp[0][i][j] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int val = dp[i-1][j][2];    // add P
                    if (j > 0) val = (val + dp[i-1][j-1][2]) % mod; // add A
                    if (k > 0) val = (val + dp[i-1][j][k-1]) % mod; // add L
                    dp[i][j][k] = val;
                }
            }
        }

        return dp[n][1][2];
    }
};

int main() {
    Solution s;
    cout << s.checkRecord(2) << endl;
}