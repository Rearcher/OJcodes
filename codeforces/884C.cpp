#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void dfs(int node, int& cnt, vector<bool>& visited, vector<int>& p) {
    if (visited[node-1]) return;
    visited[node-1] = true;
    cnt++;
    dfs(p[node-1], cnt, visited, p);
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    
    vector<bool> visited(n, false);
    vector<int> cycles;

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        dfs(i, cnt, visited, p);
        if (cnt > 0) cycles.push_back(cnt);
    }

    if (cycles.size() <= 2) {
        cout << 1LL * n * n << endl;
        return 0;
    }
    
    sort(cycles.begin(), cycles.end(), [&](int a, int b){return a > b;});
    long long ans = pow(cycles[0] + cycles[1], 2);
    for (int i = 2; i < cycles.size(); ++i)
        ans += 1LL * cycles[i] * cycles[i];
    cout << ans << endl;

    return 0;
}