#include <cstdio>
typedef unsigned long long ull;
ull dp[105][1005][2];
const ull limit = 100000000000000000;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    dp[0][0][1] = 1;
    for (int i = 1; i <= k; ++i) {
        dp[i][0][1] = 1;
        for (int j = 1; j <= n; ++j) {
            if (j < i) {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i - 1][j][1];
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - i][0];
                dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - i][1];

                dp[i][j][0] += dp[i][j][1] / limit;
                dp[i][j][1] %= limit;
            }
        }
    }
    if (dp[k][n][0]) printf("%llu", dp[k][n][0]);
    printf("%llu\n", dp[k][n][1]);

    return 0;
}
