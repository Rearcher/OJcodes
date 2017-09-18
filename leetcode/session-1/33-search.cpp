class Solution {
public:
	int search(vector<int>& nums, int target) {
		unordered_map<int,int> hmap;
		for(int i=0; i<nums.size(); i++) hmap[nums[i]]=i;
		if(hmap.find(target)!=hmap.end()) return hmap[target];
		else return -1;
	}
};

//Solution 2=====================================================

class Solution {
public:	
	int find(vector<int>& nums, int lo, int hi, int target) {
		while(lo<hi) {
			int mid=(lo+hi)/2;
			if(nums[mid]==target) return mid;
			else if(nums[mid]>target) hi=mid-1;
			else lo=mid+1;
		}
		if(nums[lo]==target) return lo;
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int pivot=0,i;
		for(i=0; i<nums.size()-1; i++) {
			if(nums[i]>nums[i+1]) {pivot=i; break;}
		}
		if(i==nums.size()-1) return find(nums,0,nums.size()-1,target);

		if(find(nums,0,pivot,target)==-1)
			return find(nums,pivot+1,nums.size()-1,target);
		return find(nums,0,pivot,target);
	}
};
