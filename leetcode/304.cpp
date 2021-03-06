// 304. Range Sum Query 2D - Immutable
#include "leetcode.hpp"
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0;
        dp = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }

private:
    vector<vector<int>> dp;
};

int main() {

}