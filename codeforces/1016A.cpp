#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m;

    long long sum = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;

        int cur = sum / m;
        cout << cur - last << " ";
        last = cur;
    }
    return 0;
}
