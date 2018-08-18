#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    long long n, k;
    cin >> n >> k;

    if (n == 1 || k <= 2) {
        cout << 0;
        return 0;
    }

    long long half = k / 2 + 1;

    long long res = 0;
    if (n < half) res = 0;
    else if (n == half) res = 1;
    else if (n > half && n < k - 1) {
        res = n - half + 1;
    } else {
        res = k - half;
    }
    cout << res << "\n";
    return 0;
}
