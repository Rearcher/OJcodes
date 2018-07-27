#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);
    int n, k;
    cin >> n >> k;
    
    vector<char> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    sort(s.begin(), s.end());
    
    int i = 0, res = s[0] - 'a' + 1;
    char last = s[0];
    for (int j = 2; j <= k; ++j) {
        i++;
        while (i < n && s[i] - last <= 1) i++;
        if (i >= n) {
            cout << "-1\n";
            return 0;
        }

        res += s[i] - 'a' + 1;
        last = s[i];
    }
    cout << res;
}
