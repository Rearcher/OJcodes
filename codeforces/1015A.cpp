#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; ++j)
            a[j] = 1;
    }

    vector<int> res;
    for (int i = 1; i <= m; ++i)
        if (a[i] == 0) res.push_back(i);
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
}