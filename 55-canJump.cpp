class Solution {
public:
	bool canJump(vector<int>& nums) {
		if(nums.size()<=1) return true;
		int pos=0, n=nums.size();
		while(pos<n) {
			if(pos+nums[pos]>=n-1) return true;
			if(nums[pos]==0) return false;
			int maxStep=nums[pos];
			int pos_c=pos, max=0;
			for(int i=1; i<=maxStep; i++) {
				if(i+nums[pos_c+i]>max) {
					max = i+nums[pos_c+i];
					pos = pos_c+i;
				}
			}
		}
	}
};
