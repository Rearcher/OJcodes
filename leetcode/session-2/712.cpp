// 712. Minimum ASCII Delete Sum for Two Strings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        int maxSum = INT_MIN;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    sum[i][j] = sum[i-1][j-1] + s1[i-1]; 
                } else {
                    sum[i][j] = max(sum[i][j-1], sum[i-1][j]);
                }
                maxSum = max(maxSum, sum[i][j]);
            }
        }

        int totalSum = 0;
        for (char c : s1) totalSum += c;
        for (char c : s2) totalSum += c;
        return totalSum - maxSum * 2;
    }
};

int main() {
    Solution s;
    cout << s.minimumDeleteSum("ihlnqpdwqgcd", "mgrumwmpjedv") << endl;
}