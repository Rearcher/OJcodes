#include <iostream>
#include <algorithm>
using namespace std;

int a[1005], n;

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);

        bool ok = true;
        int ans = 0;
        for (int i = n - 1; i >= 0 && ok; --i) {
            for (int j = n - 1; j >= 0 && ok; --j) {
                if (i == j) continue;
                ans = a[i] - a[j];
                for (int l = 0, r = j - 1; ok && l < r;) {
                    if (a[l] + a[r] == ans) ans = a[i], ok = false;
                    else if (a[l] + a[r] > ans) r--;
                    else l++;
                }
            }
        }
        if (ok) cout << "no solution\n";
        else cout << ans << "\n";
    }
    return 0;
}