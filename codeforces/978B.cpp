#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int i = 0, res = 0;
    while (i < n) {
        if (s[i] != 'x') {
            i++;
            continue;
        }

        int j = i + 1;
        while (j < n && s[j] == 'x') j++;
        int x_cnt = j - i;

        if (x_cnt >= 3) {
            res += x_cnt - 2;
        }
        i = j;
    }
    cout << res << "\n";
}