// 560. Subarray Sum Equals K
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, result = 0;

        m[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.count(sum - k)) {
                result += m[sum - k];
            }

            if (m.count(sum)) {
                m[sum] += 1;
            } else {
                m[sum] = 1;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 1};
    cout << s.subarraySum(nums, 2) << endl;
}