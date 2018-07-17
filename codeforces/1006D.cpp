#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("codeforces/input", "r", stdin);

    int n;
    string a, b;
    cin >> n >> a >> b;

    int res = 0, i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            if (a[i] != b[i]) res++;
            break;
        }

        if ((a[i] == a[j] && b[i] == b[j]) || (a[i] == b[i] && a[j] == b[j]) || (a[i] == b[j] && a[j] == b[i])) {
            res += 0;
        } else if (b[i] == b[j] || a[i] == b[i] || a[i] == b[j] || a[j] == b[j] || a[j] == b[i]) {
            res += 1;
        } else {
            res += 2;
        }

        i++, j--;
    }
    cout << res;

    return 0;
}
