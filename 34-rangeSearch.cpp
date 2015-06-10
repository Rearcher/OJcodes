class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int lo=0, hi=nums.size()-1;
		int l, r, t;
		vector<int> ans;
		bool flag=false;
		while(lo<hi) {
			int mid=(lo+hi)/2;
			if(nums[mid]==target) {
				t = mid;
				flag = true;
				break;
			}
			if(nums[mid]<target) lo=mid+1;
			else hi=mid-1;
		}
		if(nums[lo]==target) {t = lo; flag = true;}
	
		if(!flag) {
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}

		for(r=t; r+1<nums.size()&&nums[r+1]==nums[r]; r++);
		for(l=t; l-1>0&&nums[l-1]==nums[l]; l--);

		ans.push_back(l);
		ans.push_back(r);
	
		return ans;
	}
};
