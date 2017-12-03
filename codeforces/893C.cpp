#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

void dfs(vector<bool>& visited, vector<int>& cost, unordered_map<int, unordered_set<int>>& edges, int start, set<int>& s) {
    visited[start] = true;
    s.insert(cost[start]);

    if (!edges.count(start)) {
        return;
    }

    for (int next : edges[start]) {
        if (visited[next]) continue;
        dfs(visited, cost, edges, next, s);
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cost(n);
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    
    unordered_map<int, unordered_set<int>> edges;
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        edges[x - 1].insert(y - 1);
        edges[y - 1].insert(x - 1);
    }

    vector<bool> visited(n, false);
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        set<int> s;
        dfs(visited, cost, edges, i, s);
        result += *s.begin();
    }
    cout << result << endl;
    return 0;
}