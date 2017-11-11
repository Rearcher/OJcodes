#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;
    int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < n; ++i) {
        switch(s[i]) {
            case 'L':
                l++;
                break;
            case 'U':
                u++;
                break;
            case 'R':
                r++;
                break;
            case 'D':
                d++;
                break;
        }
    }

    int res = min(l, r) + min(u, d);
    cout << res * 2 << endl;
    return 0;
}