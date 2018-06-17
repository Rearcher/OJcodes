// 852. Peak Index in a Mountain Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0, n = A.size();
        while (i + 1 < n && A[i + 1] > A[i]) i++;
        return i;
    }
};