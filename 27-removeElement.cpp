class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if(nums.empty()) return 0;
		vector<int>::iterator it;
		for(it=nums.begin(); it!=nums.end();) { 
			if(*it==val) it=nums.erase(it);
			else it++;
		}
		return nums.size();
	}
};

