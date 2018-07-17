#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("codeforces/input", "r", stdin);

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    int i = -1, j = n;
    long long sumForward = 0, sumBackward = 0;
    long long res = 0;
    while (i < j) {
        if (sumForward == sumBackward) {
            res = sumForward;
            sumForward += d[++i];
            sumBackward += d[--j];
        } else if (sumForward > sumBackward) {
            sumBackward += d[--j];
        } else {
            sumForward += d[++i];
        }
    }
    cout << res << "\n";
}
