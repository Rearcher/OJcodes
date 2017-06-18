// 624. Maximum Distance in Arrays
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> maxs, mins;
        for (int i = 0; i < arrays.size(); ++i) {
            mins.push_back(pair<int, int>{arrays[i][0], i});
            maxs.push_back(pair<int, int>{arrays[i][arrays[i].size() - 1], i});
        }

        sort(mins.begin(), mins.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        });
        sort(maxs.begin(), maxs.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });

        int result = 0;
        if (mins[0].second != maxs[0].second) {
            result = maxs[0].first - mins[0].first;
        } else {
            result = max(maxs[0].first - mins[1].first, maxs[1].first - mins[0].first);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> arrays = {{1, 2, 3, 5}, {4, 5}, {2, 3}};
    Solution s;
    cout << s.maxDistance(arrays) << endl;
}