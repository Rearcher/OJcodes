#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 2005;
int p[MAX_N], sz[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    while (p[x] != x) {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if (sz[rx] < sz[ry]) {
        p[rx] = ry;
        sz[ry] += sz[rx];
    } else {
        p[ry] = rx;
        sz[rx] += sz[ry];
    }
}

typedef struct edge  {
    int u, v, w;
    bool operator < (const edge& rhs) const {
        return w < rhs.w;
    }
} edge;

edge e[10010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    
    sort(e, e + m);
    init(n);

    int res = 0;
    for (int i = 0; i < m; ++i) {
        if (find(e[i].u) != find(e[i].v)) {
            res = max(res, e[i].w);
            unite(e[i].u, e[i].v);
        }
    }
    printf("%d\n", res);
}