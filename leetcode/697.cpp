// 697. Degree of an Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, pair<int, int>> index;

        int maxCnt = 0;
        vector<int> maxEle;
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]]++;
            if (maxCnt < cnt[nums[i]]) {
                maxEle = {nums[i]};
                maxCnt = cnt[nums[i]];
            } else if (maxCnt == cnt[nums[i]]) {
                maxEle.push_back(nums[i]);
            }

            if (index.count(nums[i])) {
                pair<int, int> last = index[nums[i]];
                index[nums[i]] = {last.first, i};
            } else {
                index[nums[i]] = {i, i};
            }
        }

        int ans = INT_MAX;
        for (int i : maxEle) {
            ans = min(ans, index[i].second - index[i].first + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,1,1,2,1,3,3,3,1,3,1,3,2};

    cout << s.findShortestSubArray(nums) << endl;
}