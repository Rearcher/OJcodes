// #hard
// #dynamic programming
// #dp
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        
        for (auto x : rods) {
            unordered_map<int, int> cur(dp);
            for (auto iter : cur) {
                int old = iter.first;
                dp[old + x] = max(dp[old + x], cur[old]);
                dp[abs(old - x)] = max(dp[abs(old - x)], cur[old] + min(x, old));
            }
        }
        
        return dp[0];
    }
};