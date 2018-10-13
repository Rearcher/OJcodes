#include <iostream>
#include <algorithm>
using namespace std;

int a[50005];
int l, n, m;

bool valid(int d) {
    int start = 0, cnt = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] - a[start] < d) cnt++;
        else start = i;
    }
    if (cnt > m) return false;
    return true;
}

int main() {
    // freopen("input", "r", stdin);
    cin >> l >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = 0;
    a[n + 1] = l;
    sort(a, a + n + 2);

    int lo = 0, hi = l, mid;
    int res = 0;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (valid(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << endl;
}