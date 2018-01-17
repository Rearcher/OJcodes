// 764. Largest Plus Sign
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> m;
        for (auto v : mines) m.insert(v[0] * N + v[1]);

        for (int i = 0; i < N; ++i) {            
            int count = 0;
            for (int j = 0; j < N; ++j) {
                count = m.count(i * N + j) ? 0 : count + 1;
                dp[i][j] = count;
            }

            count = 0;
            for (int j = N - 1; j >= 0; --j) {
                count = m.count(i * N + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        int result = 0;
        for (int j = 0; j < N; ++j) {
            int count = 0;
            for (int i = 0; i < N; ++i) {
                count = m.count(i * N + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
            }

            count = 0;
            for (int i = N - 1; i >= 0; --i) {
                count = m.count(i * N + j) ? 0 : count + 1;
                dp[i][j] = min(dp[i][j], count);
                result = max(result, dp[i][j]);
            }
        }    
        return result;  
    }
};

int main() {
    Solution s;
    vector<vector<int>> mines{{4, 2}};
    cout << s.orderOfLargestPlusSign(5, mines) << endl;
}