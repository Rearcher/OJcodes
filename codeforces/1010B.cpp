#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);
    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cout << 1 << endl;
        cin >> a[i];

        if (a[i] == 0) return 0;
    }

    int l = 1, r = m + 1, t = 2, cnt = 0;
    while (t) {
        cout << (l + r) / 2 << endl;
        cin >> t;

        t *= a[cnt % n];
        if (t == 0) return 0;
        else if (t == 1) l = (l + r) / 2 + 1;
        else r = (l + r) / 2 - 1;

        cnt++;
    }
    return 0;
}
