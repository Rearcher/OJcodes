#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    int cnt = 0, i = 0, j = 0;
    while (i < n && j < m) {
        long long sum1 = a[i], sum2 = b[j];
        while (i < n && j < m && sum1 != sum2) {
            if (sum1 < sum2) {
                sum1 += a[++i];
            } else {
                sum2 += b[++j];
            }
        }
        if (sum1 != sum2) {
            cout << "-1\n";
            return 0;
        }
        cnt++;
        i++;
        j++;
    }
    if (i < n || j < m) cout << "-1\n";
    else cout << cnt;
    return 0;
}
