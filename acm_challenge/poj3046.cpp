#include <cstdio>
using namespace std;

int cnt[1005];
int dp[1005][100005];

int main() {
    // freopen("input", "r", stdin);

    int t, a, s, b;
    scanf("%d%d%d%d", &t, &a, &s, &b);

    int temp;
    for (int i = 0; i < a; ++i) {
        scanf("%d", &temp);    
        cnt[temp]++;
    }

    int res = 0, mod = 1e6;
    for (int i = 0; i <= t; ++i) dp[i][0] = 1;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= a; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            if (cnt[i] <= j - 1) {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - cnt[i]] + mod) % mod;
            }
        }
    }
    for (int i = s; i <= b; ++i) res = (res + dp[t][i]) % mod;
    printf("%d\n", res);

    return 0;
}