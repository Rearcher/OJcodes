#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << "YES\n" << x << endl;
        return 0;
    }

    if(n == 2) {
        if(x == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n0 " << x;
        }
        return 0;
    }

    cout << "YES\n";
    for(int i = 0; i < n - 3; ++i) {
        cout << i << " ";
        x ^= i;
    }

    int a = 1 << 18;
    int b = 1 << 19;
    cout << (a ^ x) << " " << b << " " << (a ^ b);
    return 0;
}
