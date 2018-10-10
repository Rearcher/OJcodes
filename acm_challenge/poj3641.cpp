#include <iostream>
#include <cmath>
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

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(1.0 * n); ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int p, a;
    while (cin >> p >> a) {
        if (p == 0 && a == 0) break;
        if (!is_prime(p) && quick_pow(a, p, p) == a) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}