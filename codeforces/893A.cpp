#include <iostream>
using namespace std;

int main() {
    int n, a, x, y;
    cin >> n;

    x = 1;
    y = 2;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (x != a && y != a) {
            cout << "NO\n";
            return 0;
        }

        if (x == a) y = 6 - x - y;
        if (y == a) x = 6 - x - y;
    }

    cout << "YES\n";
    return 0;
}