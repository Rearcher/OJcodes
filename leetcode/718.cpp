// 718. Maximum Length of Repeated Subarray
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<int> dp(n, 0);

        int result = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> temp(n, 0);
            temp[0] = A[i] == B[0] ? 1 : 0;
            for (int j = 1; j < n; ++j) {
                if (A[i] == B[j]) {
                    temp[j] = dp[j-1] + 1;
                    result = max(temp[j], result);
                }
                else temp[j] = 0;
            }
            dp = temp;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> A{1, 2, 3, 2, 1, 2};
    vector<int> B{3, 2, 1, 2, 4, 7};
    cout << s.findLength(A, B) << endl;
}