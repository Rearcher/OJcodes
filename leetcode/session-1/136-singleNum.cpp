class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if(nums.size()==1) return nums[0];
		unordered_map<int,int> hmap;
		for(int i=0; i<nums.size(); i++) {
			if(hmap.find(nums[i])==hmap.end())
				hmap[nums[i]] = i;
			else 
				hmap.erase(nums[i]);
		}
		unordered_map<int,int>::iterator it=hmap.begin();
		return it->first;
	}
};
