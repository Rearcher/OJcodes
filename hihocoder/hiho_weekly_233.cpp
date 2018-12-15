#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100010];
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector<ll> dp(n + 1, 0);
    ll sum = 1;
    unordered_map<int, ll> h;
    h[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (sum - h[a[i]] + MOD) % MOD;
        sum = (sum + dp[i]) % MOD;
        h[a[i]] = (h[a[i]] + dp[i]) % MOD;
    }
    cout << dp[n] << "\n";
}