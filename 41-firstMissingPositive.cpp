class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= 0) hmap[nums[i]]=i;
        }
        int ans=1;
        while(true) {
            if(hmap.find(ans)!=hmap.end()) ans++;
            else return ans;
        }
        return ans;
    }
};
