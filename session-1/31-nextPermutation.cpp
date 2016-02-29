class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if(nums.size()<2) return;
		int i,k;
		for(i=nums.size()-2; i>=0; i--) {
			if(nums[i] < nums[i+1]) break;
		}
		for(k=nums.size()-1; k>=0; k--) {
			if(nums[k] > nums[i]) break;
		}
		if(i >= 0) swap(nums[i], nums[k]);
		reverse(nums.begin()+i+1, nums.end());
	}
};
