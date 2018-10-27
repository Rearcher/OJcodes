#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 1005;

typedef struct edge {
    int to, cost;
    edge() {}
    edge(int _to, int _cost) : to(_to), cost(_cost) {}
} edge;

typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

int dijkstra(int s, int x) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V + 1, 0x3f3f3f3f);
    
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            int tmp = d[v] + (e.cost >= x ? 1 : 0);
            if (d[e.to] > tmp) {
                d[e.to] = tmp;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d[V];
}

int main() {
    int p, k;
    scanf("%d%d%d", &V, &p, &k);

    int a, b, c;
    for (int i = 0; i < p; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(edge(b, c));
        G[b].push_back(edge(a, c));
    }

    int lb = 0, ub = 1e6 + 2;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (dijkstra(1, mid) > k) lb = mid;
        else ub = mid;
    }
    if (lb > 1e6) printf("-1\n");
    else printf("%d\n", lb);

    return 0;
}

