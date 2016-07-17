// Burst Balloons
public class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;

        int[]arr = new int[n+2];
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) arr[i+1] = nums[i];
        }
        arr[0] = arr[n+1] = 1;

        int[][] dp = new int[n+2][n+2];
        for (int len = 1; len <= n; ++len) {
            for (int start = 1; start <= n - len + 1; ++start) {
                int end = start + len - 1;
                int bestCoins = 0;
                for (int i = start; i <= end; ++i) {
                    int coins = dp[start][i-1] + dp[i+1][end];
                    coins += arr[start-1] * arr[i] * arr[end+1];
                    if (coins > bestCoins) bestCoins = coins;
                }
                dp[start][end] = bestCoins;
            }
        }
        return dp[1][n];
    }
}
