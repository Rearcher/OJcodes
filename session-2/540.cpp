// 540. Single Element in a Sorted Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n / 2;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[2*mid] != nums[2*mid+1]) right = mid;
            else left = mid + 1;
        }        

        return nums[2*left];
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, 2, 3, 3};
    cout << s.singleNonDuplicate(nums) << endl;
}