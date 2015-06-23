class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if(nums.size()<=1) return false;
		map<int,int> hmap;
		for(auto i : nums) {
			if(hmap.find(i)==hmap.end()) 
				hmap[i] = 1;
			else
				return true;
		}
		return false;
	}
};
