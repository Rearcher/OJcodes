// 645. Set Mismatch
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int duplicate, sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        for (int num : nums) {
            if (s.count(num)) {
                duplicate = num;
                break;
            }
            s.insert(num);
        }

        return vector<int>{duplicate, n * (n + 1) / 2 - sum + duplicate};
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 2, 4};
    vector<int> result = s.findErrorNums(nums);

    cout << result[0] << " " << result[1] << "\n";
}