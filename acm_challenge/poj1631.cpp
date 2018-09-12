#include <cstdio>
#include <algorithm>
using namespace std;

int p[40005];
int dp[40005];

int main() {
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        for (int i = 1; i <= t; ++i) {
            scanf("%d", &p[i]);
            dp[i] = 1e8;
        }

        int len = 1;
        for (int i = 1; i <= t; ++i) {
            int k = lower_bound(dp + 1, dp + 1 + t, p[i]) - dp;
            dp[k] = p[i];
            len = max(len, k);
        }
        printf("%d\n", len);
    }
}