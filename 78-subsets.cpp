class Solution {
public:
	void backtracking(vector<vector<int> >& ans, vector<int>& t, vector<int>& nums, int depth, int index) {
		ans.push_back(t);
		if(depth==nums.size()) return;
		for(int i=index; i<nums.size(); i++) {
			t.push_back(nums[i]);
			backtracking(ans,t,nums,depth+1, i+1);
			t.pop_back();
		}
		return;
	}

	vector<vector<int> > subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		vector<int> t;
		if(nums.empty()) return ans;	
		backtracking(ans,t,nums,0,0);
		return ans;
	}
};
