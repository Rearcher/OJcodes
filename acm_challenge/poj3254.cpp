#include <iostream>
using namespace std;

int n, m, a[13];
int dp[13][(1 << 12) + 10];

const int MOD = 1e8;

int main() {
    int x;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            a[i] = (a[i] << 1) + x;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            // 不能相邻
            if ((j & (j >> 1)) != 0) continue;
            // 必须放在可以种植的地上
            if ((a[i] | j) != a[i]) continue;

            for (int k = 0; k < (1 << n); ++k) {
                // 与上一行相同位置处不能放
                if (dp[i - 1][k] && (j & k) == 0) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    int res = 0;
    for (int j = 0; j < (1 << n); ++j) {
        res += dp[m][j];
        res %= MOD;
    }
    cout << res << "\n";
}