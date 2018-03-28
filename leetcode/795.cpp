// 795. Number of Subarrays with Bounded Maximum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, heads = 0, tails = 0;
        for (int a : A) {
            if (a >= L && a <= R) {
                heads += tails + 1;
                tails = 0;
                res += heads;
            } else if (a < L) {
                tails += 1;
                res += heads;
            } else {
                heads = 0;
                tails = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A{2, 1, 4, 3};
    cout << s.numSubarrayBoundedMax(A, 2, 3) << endl;
}