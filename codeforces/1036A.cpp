#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ull n, k;
    cin >> n >> k;

    ull res = k / n;
    if (k % n) res += 1;
    cout << res;
    return 0;
}
