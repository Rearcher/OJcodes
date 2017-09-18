// 651. 4 Keys Keyboard
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            dp[i] = i;
            for (int j = 3; j < i; ++j)
                dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
        return dp[N];
    }
};

int main() {
    Solution s;
    // cout << s.maxA(3) << endl;
    // cout << s.maxA(7) << endl;
    cout << s.maxA(9) << endl;
}