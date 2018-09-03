#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[2020];
int cost[26], dp[2020][2020];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    getchar();

    char c;
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%c%d%d", &c, &a, &b);
        getchar();
        cost[c - 'a'] = min(a, b);
    }

    for (int len = 2; len <= m; ++len) {
        for (int i = 0; i + len <= m; ++i) {
            int j = i + len - 1;
            dp[i][j] = min(dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
            if (s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        }
    }
    printf("%d\n", dp[0][m - 1]);
}