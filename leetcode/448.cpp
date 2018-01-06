// 448. Find All Numbers Disappeared in an Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDisappearedNumbers(nums);
    for (int i : result)
        cout << i << " ";
    cout << "\n";
}