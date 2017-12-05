// 740. Delete and Earn
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        for (int num : nums) cnt[num]++;

        int take = 0, skip = 0;
        for (int i = 0; i < 10001; ++i) {
            int takeI = skip + cnt[i] * i;
            int skipI = max(skip, take);
            take = takeI;
            skip = skipI;
        }

        return max(take, skip);
    }
};

int main() {
    Solution s;
    vector<int> nums{2, 2, 3, 3, 3, 4};
    cout << s.deleteAndEarn(nums) << endl;
}