#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

ll quick_mul(ll a, ll b, ll m) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

ll quick_pow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = quick_mul(res, a, m);
        a = quick_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool check(ll a, ll x, ll n, ll r) {
    ll res = quick_pow(a, x, n);
    ll last = res;
    for (int i = 0; i < r; ++i) {
        res = quick_mul(res, res, n);
        if (res == 1 && last != 1 && last != n - 1) return true;
        last = res;
    }
    if (res != 1) return true;
    return false;
}

bool miller_rabin(ll n, int times=20) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;

    ll x = n - 1, r = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        r++;
    }

    for (int i = 0; i < times; ++i) {
        ll a = rand() % (n - 1) + 1;
        if (check(a, x, n, r)) return false;
    }
    return true;
}

ll factor[100];
map<ll, ll> mp;
int tot;

ll gcd(ll a, ll b) {
    if (a < 0) return gcd(-a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll pollard_rho(ll x, ll c) {
    ll i = 1, k = 2;
    ll x0 = rand() % x;
    ll y = x0;

    while (true) {
        i++;
        x0 = (quick_mul(x0, x0, x) + c) % x;
        ll d = gcd(y - x0, x);
        if (d != 1 && d != x) return d;
        if (y == x0) return x;
        if (i == k) {
            y = x0;
            k += k;
        }
    }
}

void factorize(ll n) {
    if (miller_rabin(n)) {
        factor[tot++] = n;
        mp[n]++;
        return;
    }

    ll p = n;
    while (p >= n)
        p = pollard_rho(p, rand() % (n - 1) + 1);
    factorize(p);
    factorize(n / p);
}

int main() {
    ll a, b;
    while (cin >> a >> b) {
        if (a == b) {
            printf("%lld %lld\n", a, b);
            continue;
        }
        
        tot = 0;
        mp.clear();

        ll n = b / a;
        factorize(n);
        sort(factor, factor + tot);
        tot = unique(factor, factor + tot) - factor;

        ll ans = b, aa, bb;
        ll all = (1 << tot);
        for (int i = 0; i < all; ++i) {
            ll tp1 = 1, tp2 = 1;
            for (int j = 0; j < tot; ++j) {
                if (i & (1 << j)) {
                    ll tmp = quick_pow(factor[j], mp[factor[j]]);
                    tp1 *= tmp;
                }
            }
            tp2 = n / tp1;
            if (ans > tp1 * a + tp2 * a) {
                ans = tp1 * a + tp2 * a;
                aa = min(tp1, tp2);
                bb = max(tp1, tp2);
            }
        }
        printf("%lld %lld\n", aa * a, bb * a);
    }
    return 0;
}