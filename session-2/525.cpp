// 525. Contiguous Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = (nums[i] == 0) ? -1 : nums[i];

        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.count(sum)) {
                length = max(length, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }

        return length;
    }
};

int main() {
    vector<int> nums{0, 1, 0};
    Solution s;
    cout << s.findMaxLength(nums) << endl;
}