#include <iostream>
using namespace std;

typedef long long ll;

ll quick_pow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int m, h, a, b, res = 0;
        cin >> m >> h;
        while (h--) {
            cin >> a >> b;
            res = (res + quick_pow(a, b, m)) % m;
        }
        cout << res << "\n";
    }
    return 0;
}