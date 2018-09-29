#include <cstdio>
#include <queue>
using namespace std;

const int MAX_N = 1010;
const int inf = 0x3f3f3f3f;
int g[MAX_N][MAX_N], d[MAX_N], res[MAX_N];
int visited[MAX_N];

void dijkstra(int n, int start) {
    for (int i = 1; i <= n; ++i) {
        d[i] = g[start][i];
        visited[i] = 0;
    }
    d[start] = 0;
    visited[start] = 1;

    while (true) {
        int v = -1;
        for (int i = 1; i <= n; ++i)
            if (!visited[i] && (v == -1 || d[i] < d[v]))
                v = i;
        
        if (v == -1) break;
        visited[v] = 1;

        for (int i = 1; i <= n; ++i)
            d[i] = min(d[i], d[v] + g[v][i]);
    }

    for (int i = 1; i <= n; ++i) res[i] += d[i];
}

int main() {
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    
    int a, b, c;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            g[i][j] = inf;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = c;
    }

    dijkstra(n, x);

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int temp = g[i][j];
            g[i][j] = g[j][i];
            g[j][i] = temp;
        }
    }
    dijkstra(n, x);

    int ans = -1;
    for (int i = 1; i <= n; ++i) ans = max(ans, res[i]);
    printf("%d\n", ans);
}