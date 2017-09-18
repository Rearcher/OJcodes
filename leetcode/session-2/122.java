// Best Time to Byt and Sell Stock II
public class Solution {
    public int maxProfit(int[] prices) {
      
        if (prices.length <= 1) return 0;
        
        int maxPro = 0;
        for (int i = 1; i < prices.length; ++i) {
            maxPro += Math.max(prices[i] - prices[i-1], 0);
        }
        return maxPro;
    }
}
