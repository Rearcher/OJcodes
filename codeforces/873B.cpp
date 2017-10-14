#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0, ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') cnt++;
        else cnt--;

        if (cnt == 0) {
            ans = max(ans, i + 1);
            continue;
        }

        if (m.count(cnt)) {
            ans = max(ans, i - m[cnt]);
        } else {
            m[cnt] = i;
        }
    }
    cout << ans << endl;
    return 0;
}