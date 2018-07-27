#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int g = k, a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        a %= k;
        g = __gcd(g, a);
    }

    cout << k / g << endl;
    for (int i = 0; i < k; i += g)
        cout << i << " ";
    return 0;
}
