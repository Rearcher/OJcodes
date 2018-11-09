#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[(1 << 15) + 10][16];
int dist[16][16], n;
string str[20], ans;
vector<string> a;

const int INF = 0x3f3f3f3f;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int len = min(a[i].size(), a[j].size());
            dist[i][j] = 0;
            for (int k = len; k >= 0; --k) {
                if (a[i].substr(a[i].size() - k) == a[j].substr(0, k)) {
                    dist[i][j] = a[i].size() - k;
                    break;
                }
            }
        }
    }
}

void dfs(int cur, int state) {
    if (state == 0) return;
    string tmp = "Z";
    int next;

    for (int i = 0; i < n; ++i) {
        if (!(state & (1 << i))) continue;
        if (dp[state | (1 << cur)][cur] == dp[state][i] + dist[cur][i]) {
            int idx = a[cur].size() - dist[cur][i];
            string t = a[i].substr(idx);
            if (tmp > t) {
                tmp = t;
                next = i;
            } 
        }
    }

    ans += tmp;
    dfs(next, state ^ (1 << next));
}

int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> str[i];
        a.clear();

        cout << "Scenario #" << c << ":\n";
        
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (i == j || str[i].size() > str[j].size()) continue;
                if (str[j].find(str[i]) != string::npos) {
                    ok = false;
                    break;
                }
            }
            if (ok) a.push_back(str[i]);
        }
        if (a.empty()) {
            cout << str[0] << "\n\n";
            continue;
        }

        sort(a.begin(), a.end());
        n = a.size();
        
        init();
        memset(dp, 0x3f, sizeof(dp));
        int all = 1 << n;

        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = a[i].size();
        for (int i = 0; i < all; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == INF) continue;
                for (int k = 0; k < n; ++k) {
                    if (i & (1 << k)) continue;
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[k][j]);
                }
            }
        }
        int id = 0;
        for (int i = 0; i < n; ++i)
            if (dp[all - 1][id] > dp[all - 1][i])
                id = i;

        ans = a[id];
        dfs(id, (all - 1) ^ (1 << id));
        cout << ans << "\n\n";
    }
    return 0;
}