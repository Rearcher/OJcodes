// Target Sum
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    vector<int> dp(200001, 0);
    dp[A[0] + 100000] = dp[-A[0] + 100000] = 1;
    for (int i = 1; i < n; ++i) {
        vector<int> t(dp);
        for (int j = A[i]; j + A[i] <= 200000; ++j)
            t[j] = (dp[j - A[i]] + dp[j + A[i]]) % 1000000007;
        dp = t;
    }
    cout << dp[s + 100000];
}
