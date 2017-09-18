// 477. Total Hamming Distance
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        bool reachEnd = false;

        while (!reachEnd) {
            int zeroCnt = 0, oneCnt = 0;
            reachEnd = true;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > 0) reachEnd = false;
                int bit = nums[i] & 1;
                if (bit) {
                    oneCnt += 1;
                } else {
                    zeroCnt += 1;
                }
                nums[i] >>= 1;
            }
            
            result += zeroCnt * oneCnt;
        }

        return result;
    }
};

int main() {
    vector<int> nums{4, 14, 2};
    Solution s;
    cout << s.totalHammingDistance(nums) << endl;
}