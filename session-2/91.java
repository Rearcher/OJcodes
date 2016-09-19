/*
 * 91. Decode Ways
 */
public class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        if (s.charAt(0) == '0') return 0;

        int n = s.length();
        int[] dp = new int[n+1];
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '0') {
                if (s.charAt(i - 1) >= '1' && s.charAt(i - 1) <= '2')
                    dp[i] = i - 2 > 0 ? dp[i - 2] : 1;
                else
                    return 0;
            } else {
                if (s.charAt(i - 1) == '0') {
                    dp[i] = dp[i - 1];
                } else {
                    StringBuilder temp = new StringBuilder();
                    temp.append(s.charAt(i - 1));
                    temp.append(c);
                    int tempNum = Integer.parseInt(temp.toString());
                    if (tempNum <= 26)
                        dp[i] = dp[i - 1] + (i - 2 > 0 ? dp[i - 2] : 1);
                    else
                        dp[i] = dp[i - 1];
                }
            }
        }

        return dp[n - 1];
    }
}
