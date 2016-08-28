// Coin Change
public class Solution {
    public int coinChange(int[] coins, int amount) {
       if (amount == 0) return 0;
        int[] dp = new int[amount + 1];
        for (int coin : coins)
            if (coin <= amount)
                dp[coin] = 1;
        
        if (dp[amount] == 1) return 1;
        
        for (int i = 0; i <= amount; ++i) {
            if (dp[i] == 0) continue;
            for (int j = 0; j < coins.length; j++) {
                if (i + coins[j] <= amount && (dp[i + coins[j]] == 0 || dp[i] + 1 < dp[i + coins[j]]))
                    dp[i + coins[j]] = dp[i] + 1;
            }
        }

        return dp[amount] == 0 ? -1 : dp[amount];
    }
}
