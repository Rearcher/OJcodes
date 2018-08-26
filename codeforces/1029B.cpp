#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int i = 0, res = 1;
    while (i < n) {
        int j = i;
        while (j + 1 < n && a[j + 1] <= a[j] * 2) j++;
        res = max(res, j - i + 1);
        i = j + 1;
    }
    cout << res;

    return 0;
}
