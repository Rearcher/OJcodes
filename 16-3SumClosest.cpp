class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans=0xffffffff,last_ans=0xffffffff;
		int len=nums.size();
		
		if(nums.size() < 3) return 0;

		sort(nums.begin(), nums.begin()+len);
		
		if(nums[0]+nums[1]+nums[2] >= target)
			return nums[0]+nums[1]+nums[2];

		if(nums[len-1]+nums[len-2]+nums[len-3] <= target)
			return nums[len-1]+nums[len-2]+nums[len-3];

		int p, q;
		for(int i = 0 ; i < len; i++) {
			p = i+1;
			q = len-1;
			if(i!=0 && nums[i]==nums[i-1]) continue;
			
			while(p<q) {
				last_ans = ans;
				
				ans = nums[i]+nums[p]+nums[q];
				if(ans == target) return ans;
				else if(ans > target) q--;
				else if(ans < target) p++;

				int s1=abs(last_ans-target);
				int s2=abs(ans-target);
				ans = (s1<s2 ? last_ans : ans);
			}
		}
		return ans;
	}
}
