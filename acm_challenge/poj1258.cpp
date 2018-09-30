#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 105;
const int inf = 0x3f3f3f3f;

int g[MAX_N][MAX_N], visited[MAX_N], d[MAX_N];

int prim(int n) {
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
        visited[i] = 0;
    }

    d[0] = 0;

    int res = 0;
    while (true) {
        int v = -1;
        for (int i = 0; i < n; ++i)
            if (!visited[i] && (v == -1 || d[i] < d[v]))
                v = i;
        if (v == -1) break;

        visited[v] = 1;
        res += d[v];
        for (int i = 0; i < n; ++i)
            d[i] = min(d[i], g[v][i]);
    }
    return res;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &g[i][j]);

        printf("%d\n", prim(n));
    }
}