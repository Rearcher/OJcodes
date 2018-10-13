#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int n, k;
int a[100005];

bool valid(ll x) {
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x) s += ceil(1.0 * (a[i] - x) / (k - 1));
    }
    return s <= x;
}

int main() {
    // freopen("input", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        ll lo, mid, hi = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > hi) hi = a[i];
        }
        scanf("%d", &k);

        if (k == 1) {
            printf("%lld\n", hi);
            continue;
        }

        lo = 1;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (valid(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("%lld\n", hi);
    }
}