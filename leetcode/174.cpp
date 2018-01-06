// 174. Dungeon Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int nrow = dungeon.size();
        if (nrow == 0) return 0;

        int ncol = dungeon[0].size();
        vector<vector<int>> dp(nrow + 1, vector<int>(ncol + 1, INT_MAX));
        dp[nrow][ncol-1] = dp[nrow-1][ncol] = 1;
        
        for (int i = nrow - 1; i >= 0; --i) {
            for (int j = ncol - 1; j >= 0; --j) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};

int main() {
    Solution s;
    // vector<vector<int>> dungeons{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    vector<vector<int>> dungeons{{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    cout << s.calculateMinimumHP(dungeons) << endl;
}