/* missing numbers */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (n+1)*n/2-accumulate(nums.begin(), nums.end(), 0);
    }

	int missingNumber_ex(vector<int>& nums) {
       int res = 0;
       for (unsigned int i = 1; i <= nums.size(); i++) {
           res ^= i;
           res ^= nums[i-1];
       }
       return res;
    }
};
