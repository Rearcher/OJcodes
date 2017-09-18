// 327. Count of Range Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        vector<long long> preSum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i)
            preSum[i] = preSum[i-1] + nums[i-1];
        return merge(preSum, 1, nums.size(), lower, upper);
    }

private:
    int merge(vector<long long>& preSum, int begin, int end, int lower, int upper) {
        if (begin == end) 
            return (preSum[begin] >= lower && preSum[begin] <= upper) ? 1 : 0;
        
        int mid = begin + (end - begin) / 2;
        int count = merge(preSum, begin, mid, lower, upper) + merge(preSum, mid + 1, end, lower, upper);
        int j = mid + 1, k = mid + 1;
        for (int i = begin; i <= mid; ++i) {
            while (j <= end && preSum[j] - preSum[i] < lower) j++;
            while (k <= end && preSum[k] - preSum[i] <= upper) k++;
            count += k - j;
        }

        inplace_merge(preSum.begin() + begin, preSum.begin() + mid + 1, preSum.begin() + end + 1);
        return count;
    }
};

int main() {
    Solution s;
    // vector<int> nums{-2, 5, -1};
    vector<int> nums{};
    cout << s.countRangeSum(nums, 0, 0) << endl;
}