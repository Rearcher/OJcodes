// 410. Split Array Largest Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long low = 0, high = 0;
        for (int num : nums) {
            if (num > low) low = num;
            high += num;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (valid(nums, mid, m)) high = mid - 1;
            else low = mid + 1;
        }

        return (int)low;
    }

private:
    bool valid(vector<int>& nums, int target, int m) {
        int cnt = 1, sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum > target) {
                sum = num;
                cnt += 1;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums{1, INT_MAX};
    Solution s;
    cout << s.splitArray(nums, 2) << endl;
}