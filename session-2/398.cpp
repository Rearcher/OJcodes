// 398. Random Pick Index
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    Solution (vector<int> nums) {
        this->nums = nums;
        srand(time(0));
    }

    int pick(int target) {
        int count = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target) continue;
            count += 1;

            int num = rand() % count;
            if (num == 0) {
                result = i;
            }
        }

        return result;
    }

private:
    vector<int> nums;
};

int main() {

}