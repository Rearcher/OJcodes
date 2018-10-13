#include <iostream>
using namespace std;

int n, m;
int a[100005];

bool isSmall(int x) {
    int cnt = 1, s = 0;
    for (int i = 0; i < n; ++i) {
        if (s + a[i] > x) {
            cnt++;
            s = a[i];
        } else {
            s += a[i];
        }
    }
    return cnt > m;
}

int main() {
    cin >> n >> m;
    int lo = 0, hi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > lo) lo = a[i];
        hi += a[i];
    }

    int mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (isSmall(mid)) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << endl;
}