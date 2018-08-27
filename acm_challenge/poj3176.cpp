#include <cstdio>
#include <algorithm>
using namespace std;

int a[355][355], dp[355][355];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);

    dp[1][1] = a[1][1];
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
            }

            if (i == n) res = max(res, dp[i][j]);
        }
    }
    printf("%d\n", res);
}