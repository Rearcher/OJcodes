#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> sum(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            sum[i] = a[i];
        } else {
            sum[i] = a[i] + sum[i - 1];
        }
    }

    long long num, idx, order;
    auto begin = sum.begin();
    while (m--) {
        cin >> num;

        auto iter1 = lower_bound(begin, sum.end(), num);
        if (*iter1 == num) {
            idx = iter1 - sum.begin();
            order = a[idx];
            cout << idx + 1 << " " << order << "\n";
            begin = iter1;
            continue;
        }

        auto iter2 = upper_bound(iter1, sum.end(), num);
        idx = iter2 - sum.begin();
        order = idx > 0 ? (num - sum[idx - 1]) : num;
        cout << idx + 1 << " " << order << "\n";
        begin = iter2;
    }
    return 0;
}