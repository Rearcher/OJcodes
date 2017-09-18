//Kadane Algorithm
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n=nums.size();
		int max_sum = INT_MIN;
		int sum=0;
		for(int i=0; i<n; i++) {
			if(sum>=0) sum += nums[i];
			else sum = nums[i];

			if(sum > max_sum) max_sum = sum;
		}
		return max_sum;
	}
};
