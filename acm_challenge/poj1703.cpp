#include <cstdio>
using namespace std;

int p[200005], rank[200005];

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

    if (rank[rx] < rank[ry]) {
        p[rx] = ry;
        rank[ry] += rank[rx];
    } else {
        p[ry] = rx;
        rank[rx] += rank[ry];
    }
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        rank[i] = 0;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        init(n * 2);
        
        char op[3];
        int x, y;
        while (m--) {
            scanf("%s%d%d", op, &x, &y);
            if (op[0] == 'A') {
                if (same(x, y)) {
                    printf("In the same gang.\n");
                } else if (same(x, y + n)) {
                    printf("In different gangs.\n");
                } else {
                    printf("Not sure yet.\n");
                }
            } else {
                unite(x, y + n);
                unite(x + n, y);
            }
        }
    }
}