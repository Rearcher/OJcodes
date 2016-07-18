// Best Time to Bun ans Sell Stock IV
public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length <= 1) return 0;
        if (k >= prices.length / 2) return hack(prices);
        
        int transaction = k;
        int[] dp = new int[prices.length];
        for (int kk = 1; kk <= transaction; ++kk) {
            int tmp = dp[0] - prices[0];
            for (int j = 1; j < prices.length; ++j) {
                int last_dp = dp[j];
                dp[j] = Math.max(dp[j-1], prices[j] + tmp);
                tmp = Math.max(last_dp - prices[j], tmp);
            }
        }

        return dp[prices.length-1];
    }
    
    private int hack(int[] prices) {
        int len = prices.length, profit = 0;
        for (int i = 1; i < len; ++i) {
            profit += Math.max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
}
