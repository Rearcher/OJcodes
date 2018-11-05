#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int like[22][22];
int dp[2][1 << 21];

int main() {
    cin >> n >> m;

    int t, x;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        for (int j = 0; j < t; ++j) {
            cin >> x;
            like[i][x] = 1;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << m); ++j) if (dp[(i - 1) & 1][j]) {
            for (int k = 1; k <= m; ++k) {
                if (like[i][k] && j != (j | (1 << (k - 1))))
                    dp[i & 1][j | (1 << (k - 1))] += dp[(i - 1) & 1][j];
            }
        }
        memset(dp[(i - 1) & 1], 0, sizeof(dp[(i - 1) & 1]));
    }

    int res = 0;
    for (int i = 0; i < (1 << m); ++i)
        res += dp[n & 1][i];
    cout << res << "\n";
}