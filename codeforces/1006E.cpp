#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
vector<vector<int>> children(N, vector<int>());
vector<int> paths, startIdx(N), endIdx(N);

void dfs(int root) {
    paths.push_back(root);
    startIdx[root] = paths.size() - 1;

    for (int child : children[root]) {
        dfs(child);
    }
    endIdx[root] = paths.size() - 1;
}

int main() {
    // freopen("codeforces/input", "r", stdin);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        int father;
        cin >> father;
        children[father].push_back(i);
    }
    dfs(1);

    int u, k;
    for (int i = 0; i < q; ++i) {
        cin >> u >> k;
        if (endIdx[u] - startIdx[u] + 1 < k) {
            cout << "-1\n";
        } else {
            cout << paths[startIdx[u] + k - 1] << "\n";
        }
    }
}
