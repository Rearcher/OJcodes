/*
 * 72. Edit Distance
 * dp[i][j] means the number of steps to convert word1[0..i-1] to word2[0..j-1]
 * if we already know dp[i-1][j-1], how can we compute dp[i][j]?
 * There are some conditions:
 * 1. word1[i-1] == word2[j-1], then dp[i][j] = dp[i-1][j-1]
 * 2. word1[i-1] != word2[j-1]
 *    1) replace word1[i-1] with word2[j-1], then dp[i][j] = dp[i-1][j-1] + 1;
 *    2) delete word1[i-1], convert word1[0..i-2] to word2[0...j-1], then dp[i][j] = dp[i-1][j] + 1;
 *    3) insert word2[j-1] to word1, convert word1[0..i-1] to word2[0..j-2], then dp[i][j] = dp[i][j-1] + 1;
 */
public class Solution {

    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m+1][n+1];
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = Math.min(dp[i-1][j-1]+1, Math.min(dp[i][j-1] + 1, dp[i-1][j] + 1));
            }
        }
        return dp[m][n];
    }

    public int minDistance2(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[] dp = new int[n+1];
        int[] snapshot = new int[n+1];
        dp[0] = 0;
        for (int j = 1; j <= n; ++j)
            dp[j] = j;

        for (int i = 1; i <= m; ++i) {
            snapshot = dp.clone();
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[j] = snapshot[j-1];
                else
                    dp[j] = Math.min(snapshot[j-1]+1, Math.min(dp[j-1]+1, snapshot[j] + 1));
            }
        }

        return dp[n];
    }
}
