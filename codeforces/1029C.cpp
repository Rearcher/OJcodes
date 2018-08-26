#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> l(n), r(n);
    multiset<int> a, b;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        a.insert(l[i]);
        b.insert(r[i]);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        auto it = a.find(l[i]);
        a.erase(it);

        it = b.find(r[i]);
        b.erase(it);

        res = max(res, *b.begin() - *a.rbegin());
        a.insert(l[i]);
        b.insert(r[i]);
    }
    cout << res;

    return 0;
}
