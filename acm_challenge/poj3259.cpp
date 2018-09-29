#include <cstdio>
using namespace std;

typedef struct edge {
    int u, v, t;
} edge;

edge e[6000];
int dist[550];

bool has_negative_loop(int n, int start, int c) {
    for (int i = 0; i <= n; ++i) 
        dist[i] = 0x3f3f3f3f;
    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < c; ++j) {
            int u = e[j].u, v = e[j].v, t = e[j].t;
            if (dist[u] != 0x3f3f3f3f  && dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
                flag = true;
            }
        }
        if (!flag) return false;
    }

    for (int j = 0; j < c; ++j) {
        int u = e[j].u, v = e[j].v, t = e[j].t;
        if (dist[u] != 0x3f3f3f3f  && dist[v] > dist[u] + t) 
            return true;
    }
    return false;
}

int main() {
    int f, n, m, w;
    scanf("%d", &f);
    while (f--) {
        scanf("%d%d%d", &n, &m, &w);
        int c = 0, u, v, t;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &t);
            e[c].u = u; e[c].v = v; e[c++].t = t;
            e[c].u = v; e[c].v = u; e[c++].t = t;
        }
        for (int i = 0; i < w; ++i) {
            scanf("%d%d%d", &u, &v, &t);
            e[c].u = u; e[c].v = v; e[c++].t = -t;
        }
        for (int i = 1; i <= n; ++i) {
            e[c].u = 0; e[c].v = i; e[c++].t = 0;
        }

        bool res = has_negative_loop(n, 0, c);
        if (res) printf("YES\n");
        else printf("NO\n");
    }
}