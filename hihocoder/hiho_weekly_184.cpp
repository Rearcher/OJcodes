// hiho一下，第184周
#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int m = accumulate(a.begin(), a.end(), 0);
    if (m < x) {
        cout << -1 << "\n";
        return 0;
    } else if (m == x) {
        cout << x << "\n";
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    dp[0][0] = dp[0][a[0]] = 1;
    int result = INT_MAX;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[i - 1][j] == 1) {
                dp[i][j] = dp[i][j + a[i]] = 1;
                if (j + a[i] >= x) result = min(result, j + a[i]);
                if (j > x) result = min(result, j);
            }
        }
    }
    cout << result << "\n";
    return 0;
}