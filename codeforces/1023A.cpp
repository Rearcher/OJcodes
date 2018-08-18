#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    int star = -1;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '*') star = i;

    if (star == -1) {
        if (s == t) cout << "YES";
        else cout << "NO";
        return 0;
    }
    string s1 = s.substr(0, star);
    string s2 = s.substr(star + 1);

    if (t.size() < s1.size() + s2.size()) {
        cout << "NO";
        return 0;
    }

    int valid = 1;
    if (t.substr(0, s1.size()) != s1) valid = 0;
    if (t.substr((int)t.size() - s2.size()) != s2) valid = 0;
    if (valid) cout << "YES";
    else cout << "NO";

    return 0;    
}
