// 581. Shortest Unsorted Continuous Subarray
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // m_min records minimum number from nums[n-1] to nums[n-1-i]
        // m_max records maximum number from nums[0] to nums[i]
        // if nums[i] < m_max, nums[i] must be included in continuous subarray
        // if nums[n-1-i] > m_min, nums[n-1-i] must be included in continuous subarray
        // if end < beg < 0 after for loop, it means vector<int> nums is sorted already, so return 0
        int n = nums.size();
        int beg = -1, end = -2, m_min = nums[n-1], m_max = nums[0];
        for (int i = 0; i < n; ++i) {
            m_max = max(m_max, nums[i]);
            m_min = min(m_min, nums[n - i - 1]);
            if (nums[i] < m_max)
                end = i;
            if (nums[n - i - 1] > m_min)
                beg = n - i - 1;
        }
        return end - beg + 1;
    }
};

int main() {
    Solution s;
    int arr[] = {2, 6, 4, 8, 10, 9, 15};
    size_t cnt = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + cnt);
    cout << s.findUnsortedSubarray(nums) << endl;
}