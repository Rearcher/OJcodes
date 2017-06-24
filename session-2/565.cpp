// 565. Array Nesting
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = 0;
            for (int k = i; nums[k] >= 0; tmp++) {
                int number = nums[k];
                nums[k] = -1;
                k = number;
            }
            result = max(result, tmp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{0, 2, 1};
    cout << s.arrayNesting(nums) << endl;
}