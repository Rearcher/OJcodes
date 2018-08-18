#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    if (n == k) {
        cout << s;
        return 0;
    }

    stack<char> st;
    int del = n / 2 - k / 2, len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            if (del > 0) {
                st.pop();
                del--;
            } else {
                st.push(s[i]);
            }
        }
    }

    string res = "";
    while (st.size()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
