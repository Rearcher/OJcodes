class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> hmap;
		for(int i = 0; i < nums.size(); i++) {
			if(hmap.find(nums[i])==hmap.end())
				hmap.insert(pair<int,int>(nums[i], i));
			if(hmap.find(target-nums[i])!=hmap.end()) {
				int n = hmap[target-nums[i]];
				if(n < i) {
					res.push_back(n+1);
					res.push_back(i+1);
				}
			}
		}
		return res;
	} 
}
