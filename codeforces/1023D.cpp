#include <bits/stdc++.h>
using namespace std;

int cnt[200005];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    // freopen("input", "r", stdin);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1, 0);
    int hq = 0, hz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == q) hq = 1;
        if (a[i] == 0) hz = 1;
    }

    if (!hq && !hz) {
        cout << "NO";
        return 0;
    }

    if (!hq) {
        for (int i = 0; i < n; ++i) if (a[i] == 0) {
            a[i] = q;
            break;
        }
    }

    if (a[0] == 0) {
        for (int i = 1; i < n; ++i) if (a[i] != 0) {
            a[0] = a[i];
            break;
        }
    }
    for (int i = 1; i < n; ++i) if (a[i] == 0) a[i] = a[i - 1];
    for (int i = 0; i < n; ++i) if (a[i] > a[i + 1]) {
        cnt[a[i]]++;
        if (cnt[a[i]] > 1) {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";

    return 0;
}
