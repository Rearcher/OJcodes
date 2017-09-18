class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= 0) hmap[nums[i]]=i;
        }
        int ans=1;
        while(true) {
            if(hmap.find(ans)!=hmap.end()) ans++;
            else return ans;
        }
        return ans;
    }
};

//another solution

int firstMissingPositive(vector<int>& nums) {
	if(nums.empty()) return 1;
	for(int i=0; i<nums.size(); i++) {
		//nums[i]<=nums.size() -------to ensure valid index
		//nums[nums[i]-1]!=nums[i] --------to avoid endless loop
		//use while,but not if -----------when do a swap, nums[i] may still need swap
		while(nums[i]>0 && nums[i]!=i+1 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]) {
			int temp = nums[i];
			nums[i] = nums[temp-1];
			nums[temp-1] = temp;
		}
	}
	int i;
	for(int i=0; i<nums.size(); i++) {
		if(nums[i]!=i+1) return i+1;
	}
	return i+1;
}
