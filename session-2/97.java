/*
 * 97. Interleaving String
 */
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length(), n = s2.length(), len = s3.length();
        if (m + n != len) return false;
        if (len == 0) return true;

        boolean [][]dp = new boolean[m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && (s2.charAt(j - 1) == s3.charAt(i + j - 1));
                else if (j == 0)
                    dp[i][j] = dp[i-1][j] && (s1.charAt(i - 1) == s3.charAt(i + j - 1));
                else
                    dp[i][j] = (dp[i-1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                            (dp[i][j-1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
            }
        }
        return dp[m][n];
    }
}
