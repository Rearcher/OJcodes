/*
 * Best Time to Buy and Sell Stock with Cooldown
 * s0-->s0 with rest
 * s0-->s1 with buy
 * s1-->s1 with rest
 * s1-->s2 with sell
 * s2-->s0 with rest
 */

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 1) return 0;
        
        int s0 = 0, s1 = -prices[0], s2 = Integer.MIN_VALUE;
        for (int i = 0; i < prices.length; ++i) {
            int temp0 = s0, temp1 = s1, temp2 = s2;
            s0 = Math.max(temp0, temp2);
            s1 = Math.max(temp0 - prices[i], temp1);
            s2 = temp1 + prices[i];
        }
        
        return Math.max(s0, s2);
    }
}
