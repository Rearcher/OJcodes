// 594. Longest Harmonious Subsequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, base = nums[i];
            while (j < nums.size() && nums[j] - base <= 1) {
                j++;
            }
            if (nums[j - 1] - base == 1) {
                result = max(j - i, result);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 1, 1};
    cout << s.findLHS(nums) << endl;
}