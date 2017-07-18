// 491. Increasing Subsequences
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, result, vector<int>{}, 0);
        return result;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int> current, int index) {
        if (current.size() > 1) result.push_back(current);

        unordered_set<int> duplicates;
        for (int i = index; i < nums.size(); ++i) {
            if ((current.empty() || nums[i] >= current.back()) && !duplicates.count(nums[i])) {
                current.push_back(nums[i]);
                dfs(nums, result, current, i + 1);
                current.pop_back();
                duplicates.insert(nums[i]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
    vector<vector<int>> result = s.findSubsequences(nums);

    for (vector<int> v : result) {
        for (int i : v) cout << i << " ";
        cout << "\n";
    }
}