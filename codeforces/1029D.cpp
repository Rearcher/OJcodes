#include <bits/stdc++.h>
using namespace std;

int len(int x) {
    if (x == 0) return 1;

    int cnt = 0;
    while (x) {
        cnt += 1;
        x /= 10;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> cnt[15];
    vector<int> a(n), l(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l[i] = len(a[i]);
        cnt[l[i]][a[i] % k]++;
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long num = a[i];
        for (int j = 1; j <= 10; ++j) {
            num = (num * 10) % k;
            auto it = cnt[j].find((k - num) % k);
            if (it != cnt[j].end()) res += it->second;
            if (l[i] == j && (num + a[i]) % k == 0) res--;
        }
    }
    cout << res;

    return 0;
}
