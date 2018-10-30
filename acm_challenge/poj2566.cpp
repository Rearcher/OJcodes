#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
pair<int, int> a[MAX_N];
int n, k;

void solve(int x) {
    int s = 0, e = 1, eps = 1e9 + 7;
    int l, r, ans;
    while (s <= n && e <= n) {
        int tmp = a[e].first - a[s].first;
        if (abs(tmp - x) < eps) {
            eps = abs(tmp - x);
            l = a[s].second;
            r = a[e].second;
            ans = tmp;
        }
        if (tmp > x) s++;
        else if (tmp < x) e++;
        else break;
        if (s == e) e++;
    }
    if (l > r) swap(l, r);
    printf("%d %d %d\n", ans, l + 1, r);
}

int main() {
    while (scanf("%d%d", &n, &k)) {
        if (n == 0 && k == 0) break;

        int s = 0, tmp;
        a[0] = pair<int, int>(0, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &tmp);
            s += tmp;
            a[i] = pair<int, int>(s, i);
        }

        sort(a, a + n + 1);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &tmp);
            solve(tmp);
        }
    }
    return 0;
}