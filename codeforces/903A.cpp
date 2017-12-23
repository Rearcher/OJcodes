#include <iostream>
using namespace std;

int main() {
    int n, x;

    cin >> n;
    while (n--) {
        cin >> x;

        if (x % 7 == 0 || x % 3 == 0 || x % 7 % 3 == 0) {
            cout << "YES\n";
            continue;
        }

        bool flag = false;
        while (x > 7) {
            x -= 7;
            if (x % 3 == 0) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}