#include <cstdio>
#include <cmath>
using namespace std;

int p[1005], x[1005], y[1005], v[1005];
double dist[1005][1005];

int find(int x) {
    while (p[x] != x) {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

void connect(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) p[rx] = ry;
}

int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        p[i] = i;
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            dist[i][j] = dist[j][i] = sqrt(pow(1.0 * x[i] - x[j], 2) + pow(1.0 * y[i] - y[j], 2));
    
    char c[10];
    int a, b;
    while (scanf("%s", c) != EOF) {
        if (c[0] == 'O') {
            scanf("%d", &a);
            a -= 1;
            v[a] = 1;
            for (int i = 0; i < n; ++i) {
                if (i != a && v[i] && dist[i][a] <= d)
                    connect(i, a);
            }
        } else {
            scanf("%d%d", &a, &b);
            a -= 1; b -= 1;
            int ra = find(a), rb = find(b);
            if (ra == rb) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
}