#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int i = 0;
    for (; i < n; ++i) {
        t -= 86400 - a[i];
        if (t <= 0) break;
    }
    if (i == n) {
        cout << n << endl;
        return 0;
    }
    cout << i + 1 << endl;
    return 0;
}