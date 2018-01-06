// 747. Largest Number At Least Twice of Others
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                idx = i;
            } else if (nums[i] > m2) {
                m2 = nums[i];
            }
        }
        return m1 >= m2 * 2 ? idx : -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{3, 6, 1, 0};
    cout << s.dominantIndex(nums) << endl;
}