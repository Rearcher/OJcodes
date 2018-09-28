#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAX_N = 305;
int d[MAX_N][MAX_N], t[MAX_N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) d[i][j] = inf;

    int c;
    while (m--) {
        scanf("%d", &c);
        for (int i = 0; i < c; ++i) scanf("%d", &t[i]);
        for (int i = 0; i < c; ++i)
            for (int j = i + 1; j < c; ++j)
                d[t[i]][t[j]] = d[t[j]][t[i]] = 1;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int res = inf;
    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (int j = 1; j <= n; ++j) temp += d[i][j];
        res = min(res, 100 * temp / (n - 1));
    }
    printf("%d\n", res);
}