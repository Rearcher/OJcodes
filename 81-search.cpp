class Solution {
public:
	bool mysearch(vector<int>& nums, int lo, int hi) {
		while(lo<hi) {
			int mid=(lo+hi)/2;
			if(nums[mid]==target) return true;
			else if(nums[mid]>target) {
				hi = mid-1;
				while(lo<hi && nums[hi-1]==nums[hi]) hi--;
			}
			else (nums[mid]<target) {
				lo = mid+1;
				while(lo<hi && nums[lo+1]==nums[lo]) lo++;
			}
		}
		if(nums[lo]==target) return true;
		return false;
	}

	bool search(vector<int>& nums, int target) {
		if(nums.empty()) return false;
		int n=nums.size(), pivot=-1;
		for(int i=0; i<nums.size()-1; i++)
			if(nums[i+1]<nums[i]) pivot = i;
		if(pivot==-1) return mysearch(nums,0,n-1,target);
		return (mysearch(nums,0,pivot,target)||mysearch(nums,pivot+1,n-1,target));	
	}
};
