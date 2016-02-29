class Solution {
public:
	void backtracking(vector<int>& nums, vector<vector<int>> &res, int n) {
		if(n==nums.size()) {
			res.push_back(nums);
			return;
		}
		for(int i=n; i<nums.size(); i++) {
			swap(nums[i],nums[n]);
			backtracking(nums,res,n+1);
			swap(nums[i],nums[n]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if(nums.empty()) return res;
		backtracking(nums,res,0);
		return res;
	}
	
};
