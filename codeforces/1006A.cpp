#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i > 0) cout << " ";
        if (num % 2) cout << num;
        else cout << num - 1;
    }
}
