// 842. Split Array into Fibonacci Sequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> nums;
        dfs(S, nums, 0);
        return nums;
    }

private:
    bool dfs(string S, vector<int>& nums, int idx) {
        if (idx >= S.size() && nums.size() >= 3) return true;

        int splitSize = (S[idx] == '0') ? 1 : 10;
        for (int i = 1; i <= splitSize && idx + i <= S.size(); ++i) {
            long long num = stoll(S.substr(idx, i));
            if (num > INT_MAX) return false;

            int sz = nums.size();
            if (sz >= 2 && nums[sz - 1] + nums[sz - 2] < num) return false;
            if (sz <= 1 || nums[sz - 1] + nums[sz - 2] == num) {
                nums.push_back(num);
                if (dfs(S, nums, idx + i)) return true;
                nums.pop_back();
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> res = s.splitIntoFibonacci("123456579");
    for (int i : res)
        cout << i << " ";
}