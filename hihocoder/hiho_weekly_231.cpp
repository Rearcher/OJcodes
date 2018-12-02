#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t, l, f, d;
    cin >> t;
    while (t--) {
        cin >> l >> f >> d;
        ll g = gcd(l, d);
        if (f > g) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}