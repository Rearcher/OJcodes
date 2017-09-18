// 674. Longest Continuous Increasing Subsequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 0, cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) cnt++;
            else {
                result = max(cnt, result);
                cnt = 1;
            }
        }
        result = max(result, cnt);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 3, 5, 4, 7};
    cout << s.findLengthOfLCIS(nums) << endl;
}