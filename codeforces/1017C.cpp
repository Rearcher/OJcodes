#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = sqrt(n);

    for (int i = 0; i < n; i += k)
        for (int j = min(n, i + k); j > i; j--)
            cout << j << " ";
    return 0;
}
