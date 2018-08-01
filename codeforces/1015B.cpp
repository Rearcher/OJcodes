#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input", "r", stdin);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<char> temp1(s.begin(), s.end()), temp2(t.begin(), t.end());
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    if (temp1 != temp2) {
        cout << "-1\n";
        return 0;
    }

    int i = 0;
    vector<int> res;
    while (i < n) {
        if (s[i] != t[i]) {
            int j = i + 1;
            while (j < n && s[j] != t[i]) j++;

            for (int k = j - 1; k >= i; --k) {
                swap(s[k + 1], s[k]);
                res.push_back(k);
            }
        }
        i++;
    }

    cout << res.size() << "\n";
    for (int i : res) cout << i + 1 << " ";
}
