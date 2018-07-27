#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) flag = true;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 1) flag = true;
    }
    if (flag) {
        cout << "-1\n";
        return 0;
    }

    double load = m, consume;
    consume = load / (b[0] - 1);
    load += consume;

    consume = load / (a[n - 1] - 1);
    load += consume;

    for (int i = n - 1; i >= 1; --i) {
        if (load > pow(10, 9) + m) {
            cout << "-1\n";
            return 0;
        }

        consume = load / (b[i] - 1);
        load += consume;

        consume = load / (a[i - 1] - 1);
        load += consume;
    }

    if (load > pow(10, 9) + m + 1e-6) {
        cout << "-1\n";
    } else {
        double res = load - m;
        printf("%llf\n", res);
    }
}
