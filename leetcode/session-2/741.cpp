// 741. Cherry Pickup
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        
        dp[0][0] = grid[0][0];
        for (int t = 1; t <= 2 * n - 2; ++t) {
            vector<vector<int>> tmp(n, vector<int>(n, INT_MIN));
            for (int i = max(0, t - (n - 1)); i <= min(n - 1, t); ++i) {
                for (int j = max(0, t - (n - 1)); j <= min(n - 1, t); ++j) {
                    if (grid[i][t - i] == -1 || grid[j][t - j] == -1) continue;
                    int val = grid[i][t - i];
                    if (i != j) val += grid[j][t - j];

                    for (int pi = i - 1; pi <= i; ++pi)
                        for (int pj = j - 1; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                tmp[i][j] = max(tmp[i][j], dp[pi][pj] + val);
                }
            }
            dp = tmp;
        }

        return max(0, dp[n - 1][n - 1]);
    }
};

int main() {
    Solution s;
    // vector<vector<int>> grid{{1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1}};
    vector<vector<int>> grid{{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    cout << s.cherryPickup(grid) << endl;
}