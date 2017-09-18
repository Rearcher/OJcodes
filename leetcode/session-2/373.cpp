// 373. Find K Pairs with Smallest Sums
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        minHeap.emplace(0, 0);

        while (k-- > 0 && minHeap.size()) {
            pair<int, int> tmp = minHeap.top();
            minHeap.pop();
            result.emplace_back(nums1[tmp.first], nums2[tmp.second]);
            if (tmp.first + 1 < nums1.size())
                minHeap.emplace(tmp.first + 1, tmp.second);
            if (tmp.first == 0 && tmp.second + 1 < nums2.size())
                minHeap.emplace(tmp.first, tmp.second + 1);
        }

        return result;
    }
};

int main() {
    vector<int> nums1{1, 7, 11};
    vector<int> nums2{2, 4, 6};
    vector<pair<int, int>> result;

    Solution s;
    result = s.kSmallestPairs(nums1, nums2, 4);
    for (int i = 0; i < result.size(); ++i)
        cout << "[" << result[i].first << ", " << result[i].second << "] ";
    cout << "\n";
}