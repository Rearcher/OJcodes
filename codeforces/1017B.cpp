#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    long long c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0' && b[i] == '0') c1++;
        if (a[i] == '0' && b[i] == '1') c2++;
        if (a[i] == '1' && b[i] == '0') c3++;
        if (a[i] == '1' && b[i] == '1') c4++;
    }
    long long res = 0;
    res += c1 * c3 + c2 * c3 + c1 * c4;
    cout << res;
}
