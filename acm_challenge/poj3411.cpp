#include <iostream>
using namespace std;

typedef struct node {
    int a, b, c, p, r;
} node;

const int INF = 0x3f3f3f3f;

node t[12];
int vis[12], n, m, ans = INF;

void dfs(int cur, int cost) {
    if (cur == n) {
        if (cost < ans) ans = cost;
        return;
    }

    for (int i = 0; i < m; ++i) {
        if (t[i].a == cur && vis[t[i].b] <= 4) {
            int next = t[i].b;
            vis[next] += 1;
            if (vis[t[i].c]) dfs(next, cost + t[i].p);
            else dfs(next, cost + t[i].r);
            vis[next] -= 1;
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> t[i].a >> t[i].b >> t[i].c >> t[i].p >> t[i].r;
    dfs(1, 0);
    if (ans == INF) cout << "impossible\n";
    else cout << ans << "\n";
}