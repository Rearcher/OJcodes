#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);

    int n, m, q;
    string s, t;
    cin >> n >> m >> q >> s >> t;

    vector<int> cnt(n, 0);
    for (int i = 0; i + m <= n; ++i) {
        if (s[i] == t[0]) {
            if (s.substr(i, m) == t) {
                cnt[i + m - 1] = 1;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        cnt[i] += cnt[i - 1];
    }

    int x, y;
    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        if (y - x + 1 < m) cout << 0 << "\n";
        else {
            x -= 1;
            y -= 1;

            int t = x + m - 2 < 0 ? 0 : cnt[x + m - 2];
            int r = cnt[y] - t;
            cout << r << "\n";
        }
    }
    return 0;
}
