// 611. Valid Triangle Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int k = binarySearch(nums, j + 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }

        return count;
    }

private:
    int binarySearch(vector<int>& nums, int start, int target) {
        int left = start, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums{1};
    cout << s.triangleNumber(nums) << endl;
}