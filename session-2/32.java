/*
 * 32. Longest Valid Parentheses
 */
public class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int res = 0;
        int dp[] = new int[n];

        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i-1) == '(') {
                    dp[i] = (i - 2 > 0) ? (dp[i-2] + 2) : 2;
                    res = Math.max(dp[i], res);
                } else {
                    if (i - dp[i-1] - 1 >= 0 && s.charAt(i - dp[i-1] - 1) == '(') {
                        dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
                        res = Math.max(dp[i], res);
                    }
                }
            }
        }

        return res;
    }
}
