// 474. Ones and Zeroes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (string str : strs) {
            int ones = count(str.begin(), str.end(), '1');
            int zeroes = str.size() - ones;

            for (int i = m; i >= zeroes; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], dp[i-zeroes][j-ones] + 1);
        }

        return dp[m][n];
    }
};

int main() {

}