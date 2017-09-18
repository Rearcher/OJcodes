// 643. Maximum Average Subarray I
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, result = INT_MIN;
        
        if (nums.size() < k) return 0;

        unordered_map<int, int> m;
        m[-1] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            m[i] = sum;

            if (i >= k - 1) {
                result = max(result, m[i] - m[i - k]);
            }
        }

        return result * 1.0 / k;
    }
};

int main() {
    vector<int> nums{9,7,3,5,6,2,0,8,1,9};
    Solution s;

    cout << s.findMaxAverage(nums, 6) << endl;
}