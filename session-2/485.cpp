// 485. Consecutive Ones
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = -1, i = 0;

        while (i < nums.size()) {
            while (i < nums.size() && nums[i] == 0) {
                i++;
            }

            int cnt = 0;
            while (i < nums.size() && nums[i] == 1) {
                i++;
                cnt++;
            }

            result = max(cnt, result);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
}