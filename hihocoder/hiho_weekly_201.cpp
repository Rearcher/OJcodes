#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int m;
    cin >> m;

    vector<vector<bool>> illegal(26, vector<bool>(26, false));
    for (int i = 0; i < m; ++i) {
        string temp;
        cin >> temp;
        illegal[temp[0] - 'a'][temp[1] - 'a'] = true;
        illegal[temp[1] - 'a'][temp[0] - 'a'] = true;
    }

    vector<int> dp(26, 0);
    for (int i = 0; i < n; ++i) {
        int idx = str[i] - 'a';
        if (!illegal[idx][idx]) dp[idx]++;
        for (int j = 0; j < 26; ++j) {
            if (idx != j && !illegal[idx][j])
                dp[idx] = max(dp[j] + 1, dp[idx]);
        }
    }

    int max_len = 0;
    for (int i = 0; i < 26; ++i)
        max_len = max(max_len, dp[i]);

    cout << n - max_len << "\n";
}