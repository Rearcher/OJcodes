#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> cnt(101);
    for (int i = 1; i <= 100; ++i)
        cnt[i] = {0, i};

    if (n > m) {
        cout << "0\n";
        return 0;
    } else if (n == m) {
        cout << "1\n";
        return 0;
    }

    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        cnt[t].first += 1;
    }
    sort(cnt.begin(), cnt.end());

    int res = 1;
    int limit = cnt.back().first;
    for (int i = limit; i >= 1; --i) {
        int cur = 0;
        for (int j = 100; j >= 0; --j) {
            if (cnt[j].first == 0) break;
            cur += cnt[j].first / i;
        }
        if (cur >= n) {
            res = i;
            break;
        }
    }
    cout << res;
}
