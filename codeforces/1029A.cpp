#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int idx = -1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) continue;
        int j = 0, t = i;
        while (t < n && j < n && s[t] == s[j]) {
            t++;
            j++;
        }
        if (t >= n) {
            idx = i; 
            break;
        }
    }

    string t = "";
    if (idx == -1) {
        for (int i = 0; i < k; ++i)
            t += s;
    } else {
        t = s;
        string left = s.substr(s.size() - idx);
        for (int i = 1; i < k; ++i)
            t += left;
    }
    cout << t;
    return 0;
}
