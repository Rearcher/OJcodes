// 506. Relative Ranks
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            rank[i] = i;
        }

        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});

        vector<string> result(nums.size());
        for (int i = 3; i < rank.size(); ++i) {
            result[rank[i]] = to_string(i + 1);
        }

        if (nums.size() > 0) {
            result[rank[0]] = "Gold Medal";
        }
        if (nums.size() > 1) {
            result[rank[1]] = "Silver Medal";
        }
        if (nums.size() > 2) {
            result[rank[2]] = "Bronze Medal";
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{5, 4, 3, 2, 1};
    vector<string> result = s.findRelativeRanks(nums);
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;
}