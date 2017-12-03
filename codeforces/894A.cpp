#include <iostream>
#include <string>
using namespace std;

void dfs(string s, int &cnt, int start, int cur) {
    if (start >= s.size()) return;

    for (int i = start; i < s.size(); ++i) {
        if (cur == 1 && s[i] == 'Q') {
            dfs(s, cnt, i + 1, cur + 1);
        } else if (cur == 2 && s[i] == 'A') {
            dfs(s, cnt, i + 1, cur + 1);
        } else if (cur == 3 && s[i] == 'Q') {
            cnt += 1;
        }
    }
}

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    dfs(s, cnt, 0, 1);
    cout << cnt << endl;
}