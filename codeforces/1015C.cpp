#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    long long sum1 = 0, sum2 = 0;
    vector<int> reduce(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        sum1 += a;
        sum2 += b;
        reduce[i] = a - b;
    }

    if (sum2 > m) {
        cout << "-1\n";
        return 0;
    }

    sort(reduce.begin(), reduce.end(), greater<int>());
    long long left = sum1 - m;
    int cnt = 0;
    while (left > 0) {
        left -= reduce[cnt];
        cnt++;
    }
    cout << cnt;
}
