// 813. Largest Sum of Averages
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(n, 0));

        vector<int> preSum(n, 0);
        preSum[0] = A[0];
        for (int i = 1; i < n; ++i)
            preSum[i] = preSum[i - 1] + A[i];

        for (int j = 0; j < n; ++j)
            dp[1][j] = 1.0 * preSum[j] / (j + 1);

        for (int k = 2; k <= K; ++k) {
            for (int j = k - 1; j < n; ++j) {
                dp[k][j] = 0;
                for (int i = k - 2; i < j; ++i) {
                    dp[k][j] = max(dp[k][j], dp[k-1][i] + 1.0 * (preSum[j] - preSum[i]) / (j - i));
                }
            }
        }
        return dp[K][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> A{9, 1, 2, 3, 9};
    cout << s.largestSumOfAverages(A, 3) << "\n";
}