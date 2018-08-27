#include <cstdio>
using namespace std;

int dp[1000010];

int main() {
    int n;
    scanf("%d", &n);

    int mod = 1000000000;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i % 2 == 0) dp[i] += dp[i / 2];
        dp[i] %= mod;
    }
    printf("%d\n", dp[n]);
}