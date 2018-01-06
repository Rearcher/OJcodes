/* 5. Longest Palindromic Substring
 * dp[i][j] = true means s.subString(i, j+1) is a palindrome
 * dp[i][j] is true depends on s.charAt(i) == s.charAt(j) && (dp[i+1][j-1] || j - i <= 2)
 */
public class Solution {

    public String longestPalindrome(String s) {
        int n = s.length();
        if (n < 2) return s;

        String res = null;
        boolean[][] dp = new boolean[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i <= 2 || dp[i+1][j-1]);
                if (dp[i][j] && (res == null || j-i+1 > res.length()))
                    res = s.substring(i, j+1);
            }
        }

        return res;
    }
}
