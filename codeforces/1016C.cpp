#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long res = 0;
    for (int i = 0; i < n; ++i) res += (long long)i * a[i];
    for (int i = 0; i < n; ++i) res += (long long)(i + n) * b[n - i - 1];

    long long cur = b[0] + 2 * b[1], t = 2;
    bool down = true;
    for (int i = 1; i < n; ++i) {
        long long temp = cur, tt = t;
        if (down) {
            for (int j = i + 1; j < n; ++j)
                temp += (++tt) * b[j];
            for (int j = n - 1; j >= i; --j)
                temp += (++tt) * a[j];
            cur += (++t) * a[i];
            if (i + 1 < n) cur += (++t) * a[i + 1];
            down = false;
        } else {
            for (int j = i + 1; j < n; ++j)
                temp += (++tt) * a[j];
            for (int j = n - 1; j >= i; --j)
                temp += (++tt) * b[j];
            cur += (++t) * b[i];
            if (i + 1 < n) cur += (++t) * b[i + 1];
            down = true;
        }
        res = max(res, temp);
    }
    cout << res;
}
