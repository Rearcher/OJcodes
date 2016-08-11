/**
 * Guess Number Higher or Lower II
 * optimal substructure(length from 2 to n)
 * dp[i][j] = min(Math.max(dp[i][k-1], dp[k+1][j]) + k), k from i+1 to j-1
 * if (i + 1 == j) dp[i][j] = i
 */ 
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n+1][n+1];
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                int min = Integer.MAX_VALUE;
                for (int k = i+1; k < j; ++k) {
                    int temp = (k == n) ? (dp[i][k-1] + k) : 
						(Math.max(dp[i][k-1], dp[k+1][j]) + k);
                    min = Math.min(temp, min);
                }
                dp[i][j] = (i + 1 == j) ? i : min;
            }
        }
        return dp[1][n];
    }
}
