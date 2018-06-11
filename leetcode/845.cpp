// 845. Longest Mountain in Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 0, n = A.size();
        int res = 0;

        while (i < n) {
            int j = i;
            while (j + 1 < n && A[j + 1] > A[j]) j++;
            if (j == i) {
                i++;
                continue;
            }

            int top = j;
            while (j + 1 < n && A[j + 1] < A[j]) j++;
            if (j == top) {
                i = j + 1;
                continue;
            }

            int cur = j - i + 1;
            if (cur >= 3) res = max(res, cur);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution s;
    // vector<int> A{2, 1, 4, 7, 3, 2, 5};
    vector<int> A{2, 1, 4, 4, 5, 7, 2};
    cout << s.longestMountain(A) << "\n";
}