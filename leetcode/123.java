/*
 * Best Time to Buy and Sell Stock III
 * dp[k][i]: the max profit up until price[i](but not ends up with price[i]) at most k transaction
 * dp[k][i] = max(dp[k][i-1], max(price[i] - price[j] + dp[k-1][j]))
 * dp[k][i] = max(dp[k][i-1], price[i] + max(dp[k-1][j] - price[j]))
 * dp[0][i] = 0
 * dp[k][0] = 0
 */

public int maxProfit(int[] prices) {
    if (prices.length <= 1) return 0;

    int transaction = 2;
    int[][] dp = new int[transaction+1][prices.length];
    for (int k = 1; k <= transaction; ++k) {
        int tmp = dp[k-1][0] - prices[0];
        for (int j = 1; j < prices.length; ++j) {
            dp[k][j] = Math.max(dp[k][j-1], prices[j] + tmp);
            tmp = Math.max(dp[k-1][j] - prices[j], tmp);
        }
    }

    return dp[transaction][prices.length-1];
}
