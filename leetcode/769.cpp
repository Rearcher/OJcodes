// 769. Max Chunks To Make Sorted
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> left_max(n), right_min(n);
        
        left_max[0] = arr[0];
        for (int i = 1; i < n; ++i)
            left_max[i] = max(arr[i], left_max[i - 1]);
        right_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i)
            right_min[i] = min(arr[i], right_min[i + 1]);

        int res = 0;
        for (int i = 0; i < n - 1; ++i)
            if (left_max[i] <= right_min[i + 1])
                res++;
        return res;
    }
};