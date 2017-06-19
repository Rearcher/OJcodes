// 442. Find All Duplicates in an Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = -nums[i];

        bool complete;
        while (true) {
            complete = true;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < 0) {
                    if (nums[-nums[i]-1] < 0) {
                        int tmp = nums[i];
                        nums[i] = nums[-tmp-1];
                        nums[-tmp-1] = 1;
                        complete = false;
                    } else {
                        nums[-nums[i]-1] += 1;
                        nums[i] = 0;
                    }
                }
            }
            if (complete) break;
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == 2) result.push_back(i + 1);

        return result;
    }

    vector<int> findDuplicates2(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) result.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return result;
    }
};

int main() {
    vector<int> nums{4, 3, 2, 8, 8, 2, 3, 1};
    Solution s;
    
    vector<int> result = s.findDuplicates2(nums);
    for (auto& r : result)
        cout << r << " ";
    cout << endl;
}