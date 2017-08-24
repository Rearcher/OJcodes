// 164. Maximum Gap
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        int nmax = nums[0], nmin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nmax = max(nmax, nums[i]);
            nmin = min(nmin, nums[i]);
        }

        int bucketSize = max(1, (nmax - nmin) / (int(nums.size()) - 1));
        int bucketNum = (nmax - nmin) / bucketSize + 1;
        vector<pair<int, int>> bucket(bucketNum, {INT_MIN, INT_MAX});
        vector<int> bucketCount(bucketNum, 0);

        for (int i = 0; i < nums.size(); ++i) {
            int id = (nums[i] - nmin) / bucketSize;
            bucketCount[id] += 1;
            bucket[id].first = max(bucket[id].first, nums[i]);
            bucket[id].second = min(bucket[id].second, nums[i]);
        }

        int last = nmin, result = INT_MIN;
        for (int i = 0; i < bucketNum; ++i) {
            if (bucketCount[i] > 0) {
                result = max(result, bucket[i].second - last);
                last = bucket[i].first;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{1, 2, 4};
    Solution s;
    cout << s.maximumGap(nums) << endl;
}