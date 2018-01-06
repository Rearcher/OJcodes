// 688. Knight Probability in ChessBoard
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<int> dr{2, 2, 1, 1, -1, -1, -2, -2};
        vector<int> dc{1, -1, 2, -2, 2, -2, 1, -1};

        vector<vector<double>> dp(N, vector<double>(N, 0));
        dp[r][c] = 1;

        while (K--) {
            vector<vector<double>> tmp(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int k = 0; k < 8; ++k) {
                        int cr = i + dr[k];
                        int cc = j + dc[k];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N)
                            tmp[cr][cc] += dp[i][j] / 8.0;
                    }
                }
            }
            dp = tmp;
        }

        double ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans += dp[i][j];
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.knightProbability(3, 2, 0, 0) << endl;
}