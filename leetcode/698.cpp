// 698. Partition to K Equal Sum Subsets
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int target = sum / k;

        sort(nums.begin(), nums.end());
        int last = nums.size() - 1;
        if (nums[last] > target) return false;
        while (last >= 0 && nums[last] == target) {
            last--;
            k--;
        }

        vector<int> groups(k, 0);
        return helper(groups, last, nums, target);
    }

private:
    bool helper(vector<int>& groups, int last, vector<int>& nums, int target) {
        if (last < 0) return true;
        int num = nums[last--];
        for (int i = 0; i < groups.size(); ++i) {
            if (groups[i] + num <= target) {
                groups[i] += num;
                if (helper(groups, last, nums, target)) return true;
                groups[i] -= num;
            }
            if (groups[i] == 0) break;
        }
        return false;
    }
};

int main() {
    // vector<int> nums{7628, 3147, 7137, 2578, 7742, 2746, 4264, 7704, 9532, 9679, 8963, 3223, 2133, 7792, 5911, 3979};
    vector<int> nums{4,3,2,3,5,2,1};
    Solution s;
    cout << s.canPartitionKSubsets(nums, 4) << endl;
}