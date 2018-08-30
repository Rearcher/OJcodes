#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node {
    int s, e, v;
    bool operator < (const node& rhs) const {
        return s < rhs.s;
    }
} node;

node a[1005];
int dp[1005];

int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);

    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].v);
    sort(a, a + m);

    int res = 0;
    for (int i = 0; i < m; ++i) {
        dp[i] = a[i].v;
        for (int j = 0; j < i; ++j) {
            if (a[j].e + r <= a[i].s)
                dp[i] = max(dp[i], dp[j] + a[i].v);
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}