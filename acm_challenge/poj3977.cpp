#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int n;
ll a[40];
map<ll, int> m;

ll ABS(ll x) {
    if (x >= 0) return x;
    return -x;
}

int main() {
    while (cin >> n && n) {
        m.clear();

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int len1 = n / 2, len2 = n - len1;
        pair<ll, int> ans = pair<ll, int>(INF, 0);

        for (int i = 1; i < (1 << len1); ++i) {
            ll sum = 0;
            int cnt = 0;
            for (int j = 0; j < len1; ++j) if ((i >> j) & 1) {
                sum += a[j];
                cnt += 1;
            }
            
            if (!m[sum] || m[sum] > cnt) m[sum] = cnt;

            pair<ll, int> tmp = pair<ll, int>(ABS(sum), cnt);
            if (ans > tmp) ans = tmp;
        }

        for (int i = 1; i < (1 << len2); ++i) {
            ll sum = 0;
            int cnt = 0;
            for (int j = 0; j < len2; ++j) if ((i >> j) & 1) {
                sum += a[j + len1];
                cnt += 1;
            }
            
            pair<ll, int> tmp = pair<ll, int>(ABS(sum), cnt);
            if (ans > tmp) ans = tmp;
            
            map<ll, int>::iterator it = m.lower_bound(-sum);
            if (it != m.end()) {
                tmp = pair<ll, int>(ABS(sum + it->first), cnt + it->second);
                if (ans > tmp) ans = tmp;
            }
            if (it != m.begin()) {
                it--;
                tmp = pair<ll, int>(ABS(sum + it->first), cnt + it->second);
                if (ans > tmp) ans = tmp;
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}