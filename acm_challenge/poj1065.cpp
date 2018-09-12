#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node {
    int l, w;
    bool operator < (const node& rhs) const {
        if (l == rhs.l) return w < rhs.w;
        return l < rhs.l;
    }
} node;

node a[5005];
int dp[5005];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].l, &a[i].w);
        }
        sort(a, a + n);

        int res = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j].w > a[i].w) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        printf("%d\n", res);
    }
}