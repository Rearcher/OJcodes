// 823. Binary Trees With Factors
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;

        int mod = pow(10, 9) + 7;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) {
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
                }
            }
        }

        int res = 0;
        for (auto it : dp) res = (res + it.second) % mod;
        return res;      
    }
};

int main() {
    Solution s;
    vector<int> A{2, 4, 5, 10};
    cout << s.numFactoredBinaryTrees(A) << endl;
}