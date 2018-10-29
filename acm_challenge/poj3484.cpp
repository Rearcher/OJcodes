#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 1e6 + 5;
typedef long long ll;
ll x[MAX_N], y[MAX_N], z[MAX_N];
int n;
char s[100];

bool judge(ll m) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (m < x[i]) continue;
        else if (m >= y[i]) cnt += (y[i] - x[i]) / z[i] + 1;
        else cnt += (m - x[i]) / z[i] + 1;
    }
    if (cnt % 2) return true;
    return false;
}

void solve() {
    ll lb = 0, ub = 1e15;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (judge(mid)) ub = mid;
        else lb = mid;
    }
    if (lb == 1e15 - 1) printf("no corruption\n");
    else {
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ub >= x[i] && ub <= y[i] && (ub - x[i]) % z[i] == 0)
                cnt++;
        }
        printf("%lld %lld\n", ub, cnt);
    }
}

int main() {
    n = 0;
    while (gets(s) != NULL) {
        if (strlen(s) != 0) {
            sscanf(s, "%lld %lld %lld", &x[n], &y[n], &z[n]);
            n++;
        } else if (n) {
            solve();
            n = 0;
        }
    }

    if (n) solve();
    return 0;
}