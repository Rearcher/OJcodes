// 632. Smallest Range
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vecIter;
        auto cmp = [&](pair<vecIter, vecIter> p1, pair<vecIter, vecIter> p2) {
            return *p1.first > *p2.first;
        };

        priority_queue<pair<vecIter, vecIter>, vector<pair<vecIter, vecIter>>, decltype(cmp)> minHeap(cmp);
        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            minHeap.push(make_pair(nums[i].begin(), nums[i].end()));
        }

        vector<int> result{left, right};
        while (true) {
            auto p = minHeap.top();
            minHeap.pop();
            p.first++;
            if (p.first == p.second)
                break;
            minHeap.push(p);
            
            left = *minHeap.top().first;
            right = max(right, *p.first);
            if (right - left < result[1] - result[0])
                result = {left, right};
        }

        return result;
    }
};

int main() {

}