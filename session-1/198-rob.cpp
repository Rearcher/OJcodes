class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		int n = nums.size();
		int dp[n], flag=1;
		dp[0] = nums[0];
		for(int i=1; i<n; i++) {
			if(!flag) {
				dp[i] = dp[i-1]+nums[i];
				flag = 1;
			}
			else {
				if(i-2>=0 && dp[i-2]+nums[i]>dp[i-1]) {
					dp[i] = dp[i-2]+nums[i];
					flag = 1;
				}
				else if(nums[i-1]<nums[i]) {
					dp[i] = nums[i];
					flag = 1;
				}
				else {
					flag = 0;
					dp[i] = dp[i-1];
				}
			}
		}
		return dp[n-1];
	}
}
