// #dp
// #dynamic programming
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 1) return A[0][0];
        
        vector<int> dp(A[0].begin(), A[0].end());
        for (int i = 1; i < n; ++i) {
            vector<int> tmp(n, 0);
            for (int j = 0; j < n; ++j) {
                tmp[j] = dp[j];
                if (j > 0) tmp[j] = min(tmp[j], dp[j - 1]);
                if (j < n - 1) tmp[j] = min(tmp[j], dp[j + 1]);
                tmp[j] += A[i][j];
            }
            dp = tmp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};