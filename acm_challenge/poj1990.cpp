#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 20001;
ll count_BIT[MAX_N], dist_BIT[MAX_N];

ll sum(ll* BIT, int i) {
    ll res = 0;
    while (i > 0) {
        res += BIT[i];
        i -= i & -i;
    }
    return res;
}

// range sum [from, to)
ll range_sum(ll* BIT, int from, int to) {
    return sum(BIT, to - 1) - sum(BIT, from - 1);
}

void add(ll* BIT, int i, ll x) {
    while (i <= MAX_N) {
        BIT[i] += x;
        i += i & -i;
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        int v = arr[i].first, x = arr[i].second;
        
        ll left_cnt = range_sum(count_BIT, 1, x), right_cnt = range_sum(count_BIT, x + 1, MAX_N);
        res += v * (left_cnt * x - range_sum(dist_BIT, 1, x));
        res += v * (range_sum(dist_BIT, x + 1, MAX_N) - right_cnt * x);

        add(count_BIT, x, 1);
        add(dist_BIT, x, x);
    }
    cout << res;
}
