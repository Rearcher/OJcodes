// 719. Find K-th Smallest Pair Distance
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int lo = 0, hi = nums.back() - nums.front();
        while (lo < hi) {
            int mid = (lo + hi) / 2, count = 0;
            for (int left = 0; left < nums.size(); ++left) {
                int right = left + 1;
                while (right < nums.size() && nums[right] - nums[left] <= mid) right++;
                count += right - left - 1;
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

int main() {
    Solution s;
    vector<int> nums{9,10,7,10,6,1,5,4,9,8};
    cout << s.smallestDistancePair(nums, 18) << endl;
}