#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int q;
    ull n, m, k;
    cin >> q;
    while (q--) {
        cin >> n >> m >> k;
        ull a = max(n, m), b = min(n, m);
        if (k < a) {
            cout << "-1\n";
            continue;
        }

        ull left = a - b, t = k - b;
        ull res;
        if (left % 2 == 1) {
            res = b + t - 1;
        } else {
            if (t % 2 == 0) res = k;
            else res = b + t - 2;
        }
        cout << res << "\n";
    }

    return 0;
}
