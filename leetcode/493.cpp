// 493. Reverse Pairs
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> bak(nums);

        sort(bak.begin(), bak.end());
        vector<int> BIT(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += query(BIT, lower_bound(bak.begin(), bak.end(), (long long)nums[i] * 2 + 1) - bak.begin() + 1);
            update(BIT, lower_bound(bak.begin(), bak.end(), nums[i]) - bak.begin() + 1, 1);
        }
        return count;
    }

private:
    // suffix binary indexed tree
    void update(vector<int>& BIT, int index, int val) {
        while (index > 0) {
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }
};

int main() {
    Solution s;
    // vector<int> nums{1, 3, 2, 3, 1};
    vector<int> nums{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout << s.reversePairs(nums) << endl;
}