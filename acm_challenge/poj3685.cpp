#include <cstdio>
using namespace std;

typedef long long ll;

ll t, n, m;

ll f(ll i, ll j) {
    return i * i + 100000 * i + j * j - 100000 * j + i * j;
}

bool valid(ll x) {
    ll cnt = 0;
    for (int j = 1; j <= n; ++j) {
        int lb = 0, ub = n + 1;
        while (ub - lb > 1) {
            int i = (lb + ub) / 2;
            ll tmp = f(i, j);
            if (tmp < x) lb = i;
            else ub = i;
        }
        cnt += lb;
    }
    return cnt < m;
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll lb = -100000 * n;
        ll ub = n * n + 100000 * n + n * n + n * n;
        while (ub - lb > 1) {
            ll x = (lb + ub) / 2;
            if (valid(x)) lb = x;
            else ub = x;
        }
        printf("%lld\n", lb);
    }
    return 0;
}