//references: https://leetcode.com/discuss/5337/dp-solution-for-triangle
class Solution { //bottom-up dp
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		int n = triangle.size();
		vector<int> dp(triangle.back());
		for(int k=n-2; k>=0; k--) {
			for(int i=0; i<=k; i++)
				dp[i] = min(dp[i],dp[i+1])+triangle[k][i];
		}
		return dp[0];
	}
};
