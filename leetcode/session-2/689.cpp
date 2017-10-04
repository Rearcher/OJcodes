// 689. Maximum Sum of 3 Non-Overlapping Subarrays
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> window(n, 0);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i-k];
            if (i >= k-1) window[i-k+1] = sum;
        }

        vector<int> left(n, 0);
        int best = 0;
        for (int i = 0; i < n; ++i) {
            if (window[i] > window[best]) best = i;
            left[i] = best;
        }

        vector<int> right(n, 0);
        best = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (window[i] >= window[best]) best = i;
            right[i] = best;
        }

        vector<int> ans{-1, -1, -1};
        for (int j = k; j + k < n; ++j) {
            int i = left[j-k], kk = right[j+k];
            if (ans[0] == -1 || window[i] + window[j] + window[kk] > window[ans[0]] + window[ans[1]] + window[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = kk;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,1,2,6,7,5,1};
    vector<int> ans = s.maxSumOfThreeSubarrays(nums, 2);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}