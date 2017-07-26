// 576. Out of Boundary Paths
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int mod = pow(10, 9) + 7;
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(m, vector<long long>(n, 0)));
        auto paths = [&](int k, int i, int j) {
            return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k % 2][i][j];
        };

        for (int k = 1; k <= N; ++k) {
            for (int ii = 0; ii < m; ++ii) {
                for (int jj = 0; jj < n; ++jj) {
                    dp[k % 2][ii][jj] = paths(k-1, ii-1, jj) + paths(k-1, ii, jj-1) + paths(k-1, ii+1, jj) + paths(k-1, ii, jj+1);
                    dp[k % 2][ii][jj] %= mod;
                }
            }
        }

        return dp[N % 2][i][j];
    }
};

int main() {
    Solution s;
    cout << s.findPaths(2, 2, 2, 0, 0) << endl;
    cout << s.findPaths(1, 3, 3, 0, 1) << endl;
    cout << s.findPaths(8, 50, 23, 5, 26) << endl;
}