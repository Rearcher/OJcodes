// 679.24 Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> temp;
        for (int num : nums)
            temp.push_back(num * 1.0);
        return helper(temp);
    }

private:
    bool helper(vector<double> nums) {
        if (nums.size() == 1) {
            return abs(24 - nums[0]) <= pow(10.0, -5);
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); ++k)
                    if (k != i && k != j) next.push_back(nums[k]);

                for (int k = 0; k < 4; ++k) {
                    if ((k == 0 || k == 2) && i > j) continue;
                    if (nums[j] == 0.0) continue;
                    switch (k) {
                        case 0: next.push_back(nums[i] + nums[j]); break;
                        case 1: next.push_back(nums[i] - nums[j]); break;
                        case 2: next.push_back(nums[i] * nums[j]); break;
                        case 3: next.push_back(nums[i] / nums[j]); break;
                    }

                    if (helper(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{4, 1, 8, 7};
    cout << s.judgePoint24(nums) << endl;
}