// Array Partition I
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0)
                result += nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = vector<int>{1,4,3,2};
    cout << s.arrayPairSum(nums) << endl;
}