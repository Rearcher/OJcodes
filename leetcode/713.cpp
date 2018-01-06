// 713. Subarray Product Less Than K
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = i; j < nums.size(); ++j) {
                product *= nums[j];
                if (product < k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums{10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    cout << s.numSubarrayProductLessThanK(nums, 19) << endl;
}