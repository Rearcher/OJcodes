// 480. Sliding Window Median
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> result;

        for (int i = k; ; ++i) {
            result.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);

            if (i == nums.size()) break;

            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i-k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<double> result = s.medianSlidingWindow(nums, 3);

    for (auto n : result) cout << n << " ";
    cout << "\n";
}
