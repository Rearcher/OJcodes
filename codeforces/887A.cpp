#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    bool flag = false;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') cnt += 1;
        if (cnt >= 6 && s[i] == '1') {
            flag = true;
            break;
        }
    }

    if (flag) cout << "yes\n";
    else cout << "no\n";
    
    return 0;
}