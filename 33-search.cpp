class Solution {
public:
	int search(vector<int>& nums, int target) {
		unordered_map<int,int> hmap;
		for(int i=0; i<nums.size(); i++) hmap[nums[i]]=i;
		if(hmap.find(target)!=hmap.end()) return hmap[target];
		else return -1;
	}
};
