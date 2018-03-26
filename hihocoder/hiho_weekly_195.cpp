#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, w, p;
    cin >> n >> m;
    vector<vector<int>> cnt(11, vector<int>(11, 0));
    for (int i = 0; i < n; ++i) {
        cin >> w >> p;
        cnt[w][p] += 1;
    }
    
    vector<int> opt_w, opt_p;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (cnt[i][j] == 0) continue;

            int cur = 1, temp = 0;
            while (temp + cur <= cnt[i][j]) {
                opt_w.push_back(i * cur);
                opt_p.push_back(j * cur);
                temp += cur;
                cur *= 2;
            }
            if (temp < cnt[i][j]) {
                opt_w.push_back(i * (cnt[i][j] - temp));
                opt_p.push_back(j * (cnt[i][j] - temp));
            }
        }
    }

    vector<int> dp(m + 1, 0);
    for (int i = 0; i < opt_w.size(); ++i) {
        for (int j = m; j >= opt_w[i]; --j)
            dp[j] = max(dp[j], dp[j - opt_w[i]] + opt_p[i]);
    }
    cout << dp[m] << "\n";
}