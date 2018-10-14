#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 50050;
typedef long long ll;
typedef struct cow {
    int w, s;
    bool operator < (const cow& rhs) const {
        return w + s > rhs.w + rhs.s;
    }
} cow;

cow cows[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &cows[i].w, &cows[i].s);
    }
    sort(cows, cows + n);

    ll total = 0, res = -0x3f3f3f3f;
    for (int i = n - 1; i >= 0; --i) {
        res = max(res, total - cows[i].s);
        total += cows[i].w;
    }
    printf("%lld\n", res);
}
