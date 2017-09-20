#include <iostream>
#include <vector>
using namespace std;

int N = 100005;
vector<vector<int>> edges(N, vector<int>{});
vector<bool> visited(N, false);
vector<int> color(N, 0);

void dfs(int s) {
    visited[s] = true;
    if (color[s] == 0) color[s] = 1;

    for (int i = 0; i < edges[s].size(); ++i) {
        int e = edges[s][i];
        if (!visited[e]) {
            color[e] = (color[s] == 1 ? 2 : 1);
            visited[e] = true;
            dfs(e);
        }
    }
}

int main() {
    int n, u, v;

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1);
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 1) cnt1 += 1;
        else if (color[i] == 2) cnt2 += 1;
    }
    long long result = cnt1 * cnt2 - n + 1;
    cout << result << endl;

    return 0;
}