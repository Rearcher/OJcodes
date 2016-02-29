class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ans;
		int len=nums.size();
		sort(nums.begin(), nums.begin()+len);
		
		//special conditions
		if(len<3) return ans;
		else if(nums[0]>0 || nums[len-1]<0) return ans;
	    
		if((nums[0]==nums[2] && nums[0]==0) || (nums[len-1]==nums[len-3] && nums[len-1]==0)) {
			vector<int> temp(3,0);
			ans.push_back(temp);
			return ans;
		}
		
		//Maintain two pointers
		int p, q;
		for(int i = 0; i < len; i++) {
			if(i!=0 && nums[i]==nums[i-1]) continue;
			p = i+1;
			q = len-1;
			while(p < q) {
				vector<int> temp;
				int sum=nums[i]+nums[p]+nums[q];
				if(sum==0) { 
					temp.push_back(nums[i]);
					temp.push_back(nums[p]);
					temp.push_back(nums[q]);
					ans.push_back(temp);
					p++;
					q--;
					while(nums[p]==nums[p-1]) p++;
					while(nums[q]==nums[q+1]) q--;
				}
				else if(sum>0) q--;
				else p++;
			}
		}
		return ans;		
	}
}

