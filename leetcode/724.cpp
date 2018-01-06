// 724. Find Pivot Index
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        vector<int> preSum(n, 0);

        preSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            preSum[i] = preSum[i-1] + nums[i];

        for (int i = 0; i < n; ++i) {
            int left, right;
            if (i == 0) left = 0;
            else left = preSum[i-1];

            if (i == n - 1) right = 0;
            else right = preSum[n-1] - preSum[i];

            if (left == right) return i;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{0};
    cout << s.pivotIndex(nums) << endl;
}