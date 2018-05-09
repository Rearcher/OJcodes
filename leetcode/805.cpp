// 805. Split Array With Same Average
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        int m = n / 2, totalSum = accumulate(A.begin(), A.end(), 0);

        bool flag = false;
        for (int i = 1; i <= m && !flag; ++i)
            if (totalSum * i % n == 0) flag = true;
        if (!flag) return false;

        vector<unordered_set<int>> sums(m + 1);
        sums[0].insert(0);

        for (int num : A) {
            for (int i = m; i >= 1; --i)
                for (const int t : sums[i - 1])
                    sums[i].insert(t + num);
        }
        for (int i = 1; i <= m; ++i)
            if (totalSum * i % n == 0 && sums[i].count(totalSum * i / n))
                return true;
        return false;
    }
};