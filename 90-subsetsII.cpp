class Solution {
public:
	void backtracking(vector<vector<int> >& ans, vector<int>& t, vector<int>& nums, int index) {
		ans.push_back(t);
		for(int i=index; i<nums.size(); i++) {
			if(i==index || nums[i]!=nums[i-1]) {
				t.push_back(nums[i]);
				backtracking(ans,t,nums, i+1);
				t.pop_back();
			}
		}
		return;
	}

	vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		vector<int> t;
		if(nums.empty()) return ans;	
		backtracking(ans,t,nums,0);
		return ans;
	}

};
