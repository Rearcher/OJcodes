class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if(nums.size()<=1) return false;
		unordered_map<int,vector<int>> hmap;
		for(int i=0; i<nums.size(); i++) {
			hmap[nums[i]].push_back(i);
		}
		for(unordered_map<int,vector<int>>::iterator it=hmap.begin(); it!=hmap.end(); it++) {
			if(it->second.size()>1) {
				for(int i=0; i<it->second.size()-1; i++) {
					if(it->second[i]+k>=it->second[i+1])
						return true;
				}
			}
		}
		return false;
	}	
}
