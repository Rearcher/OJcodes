// 532. K-diff Pairs in an Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
        
            int j = i + 1;
            while (j < nums.size()) {
                if (nums[j] - nums[i] > k)
                    break;

                if (k == 0 && nums[j] == nums[i]) {
                    cnt += 1;
                    break;
                }

                if (nums[j] - nums[i] == k && nums[j] != nums[j-1]) {
                    cnt += 1;
                    break;
                }

                j++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 2, 2, 3, 3, 3};

    cout << s.findPairs(nums, 0) << endl;
}