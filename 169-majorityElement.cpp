class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int a=0, cnt=0;
		for(int i=0; i<nums.size(); i++) {
			if(cnt==0) {
				a = nums[i];
				cnt++;
			}
			else if(nums[i]==a) {
				cnt++;
			}
			else {
				cnt--;
			}
		}
		return a;
	}
};
