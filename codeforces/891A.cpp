#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 1) cnt++;
    }
    
    if (cnt > 0) {
        cout << n - cnt << endl;
        return 0;
    }

    int t = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = i; j < n; ++j) {
            cur = gcd(cur, arr[j]);
            if (cur == 1) {
                t = min(t, j - i);
                break;
            }
        }
    }
    if (t == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << t + n - 1 << endl;
    }

    return 0;
}