#include <bits/stdc++.h>
using namespace std;

int read() {
    string s;
    cin >> s;
    
    int res = 0, m = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        res += (s[i] - '0') * m;
        m *= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[n - i - 1];

    int N = 1 << n;
    vector<int> d(N + 1, 0), cnt(N + 1, 0);
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j < n; ++j)
            if (!((i >> j) & 1)) d[i] += w[j];

    for (int i = 0; i < m; ++i) cnt[read()]++;

    vector<vector<int>> res(N + 1, vector<int>(101, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
            if (d[i ^ j] < 101) 
                res[i][d[i ^ j]] += cnt[j];
        for (int j = 1; j < 101; ++j) 
            res[i][j] += res[i][j - 1];
    }

    for (int i = 0; i < q; ++i) {
        int x = read(), y;
        cin >> y;
        cout << res[x][y] << "\n";
    }
}
