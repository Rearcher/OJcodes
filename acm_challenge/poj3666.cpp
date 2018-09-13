#include <cstdio>
#include <algorithm>
using namespace std;

int a[2010], b[2010];
int dp[2010][2010];

bool cmp(int a, int b) {
    return a > b;
}

int solve(int n) {
    for (int j = 0; j < n; ++j) dp[0][j] = abs(a[0] - b[j]);
    for (int i = 1; i < n; ++i) {
        int tmp = dp[i - 1][0];
        for (int j = 0; j < n; ++j) {
            tmp = min(tmp, dp[i - 1][j]);
            dp[i][j] = tmp + abs(a[i] - b[j]);
        }
    }
    
    int res = 0x3fffffff;
    for (int j = 0; j < n; ++j) res = min(res, dp[n - 1][j]);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int res = solve(n);
    
    sort(b, b + n, cmp);
    res = min(res, solve(n));
    printf("%d\n", res);
}