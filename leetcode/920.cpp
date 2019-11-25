// #hard
// #dp
// #dynamic programming
// #dynamic programming with mod
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = pow(10, 9) + 7;
        vector<vector<long long>> dp(N + 1, vector<long long>(L + 1, 0));
        
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= L; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] * (N - i + 1)) % mod;
                if (i > K) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1] * (i - K)) % mod;
                }
            }
        }
        
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= L; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        
        return (int)dp[N][L];
    }
};