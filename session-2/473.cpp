// 473. Matchsticks to Square
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) return false;

        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            return a > b;
        });

        return dfs(nums, 0, vector<int>(4, 0), sum / 4);
    }

private:
    bool dfs(vector<int>& nums, int index, vector<int> count, int target) {
        if (index == nums.size()) {
            if (count[0] == target && count[1] == target && count[2] == target)
                return true;
            return false;
        }

        for (int i = 0; i < count.size(); ++i) {
            if (count[i] + nums[index] > target) continue;

            count[i] += nums[index];
            if (dfs(nums, index + 1, count, target)) return true;
            count[i] -= nums[index];
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{3, 3, 3, 3, 4};

    cout << s.makesquare(nums) << endl;
}