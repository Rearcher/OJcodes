// 746. Min Cost Climbing Stairs
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }   
        return min(dp[n-1], dp[n-2]); 
    }
};

int main() {
    Solution s;
    vector<int> cost{10, 15, 20};
    cout << s.minCostClimbingStairs(cost) << endl;
}