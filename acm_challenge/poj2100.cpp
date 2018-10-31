#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
ll n;
vector<pair<ll, ll> > res;

void solve(ll x) {
    ll s = 1, e = 1, sum = 0, tmp;
    while (true) {
        while (sum < x) {
            tmp = e * e;
            sum += tmp;
            e++;
        }
        if (tmp > x) break;
        if (sum == x) {
            res.push_back(pair<ll, ll>(s, e));
        }
        sum -= s * s;
        s++;
    }

    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); ++i) {
        printf("%d", res[i].second - res[i].first);
        for (int j = res[i].first; j < res[i].second; ++j)
            printf(" %d", j);
        printf("\n");    
    }
}

int main() {
    scanf("%lld", &n);
    solve(n);
    return 0;
}