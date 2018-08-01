#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);

    long long n, k;
    long long s;
    cin >> n >> k >> s;

    long long temp = (n - 1) * k;
    if (temp < s || s < k) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    long long f = 1;

    int cur = 1;
    while (s > 0) {
        long long d = s / k;
        if (s % k != 0) d++;

        cur += d * f;
        cout << cur << " ";
        f *= -1;

        s -= d;
        k--;
    }
    return 0;
}
