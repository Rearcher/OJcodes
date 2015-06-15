class Solution {
public:
	int partition(vector<int>& nums, int lo, int hi) {
		int i=lo, j=hi+1;
		while(true) {
			while(nums[++i]<nums[lo])
				if(i==hi) break;
			while(nums[--j]>nums[lo])
				if(j==lo) break;
			if(i>=j) break;
			swap(nums,i,j);
		}
		swap(nums,lo,j); //with j, not i
		return j;
	}

	void sort(vector<int>& nums, int lo, int hi) {
		if(hi<=lo) return;
		int index=partition(nums,lo,hi);
		sort(nums, lo, index-1);
		sort(nums, index+1, hi);
	}
	/*
	void sort(vector<int>& nums, int lo, int hi) {
		if(hi<=lo) return;
		int lt=lo, gt=hi;
		int v=nums[lo];
		int i=lo;
		while(i<=gt) {
			if(nums[i] < v) swap(nums,i++,lt++);
			else if(nums[i] > v) swap(nums,i,gt--);
			else i++;
		}
		sort(nums,lo,lt-1);
		sort(nums,gt+1,hi);
	}
*/
	void sortColors(vector<int>& nums) {
		if(nums.empty()) return;
		int lo=0, hi=nums.size()-1;
		sort(nums, lo, hi);
		return;
	}
};
