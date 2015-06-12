class Solution {
public:
	int jump(vector<int>& nums) {
		int ans=0, pos=0;
		int maxStep;
		while(pos < nums.size()) {
			maxStep = nums[pos];
			if(pos+nums[pos]>=nums.size()-1) return ans+1;
			int max=0, pos_c=pos;
			for(int i=1; i<=maxStep; i++) {
				if(i+nums[pos_c+i] > max) {
					max = i+nums[pos_c+i];
					pos = pos_c+i;
				}
			}
			ans++;
		}
		return ans;
	}
};
