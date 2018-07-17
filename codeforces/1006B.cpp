#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pq.emplace(a[i], i);
        if (pq.size() > k) pq.pop();
    }

    vector<int> idx;
    int res = 0;
    while (pq.size()) {
        res += pq.top().first;
        idx.push_back(pq.top().second);
        pq.pop();
    }
    sort(idx.begin(), idx.end());

    cout << res << "\n";
    if (k == 1) {
        cout << n;
    } else {
        for (int i = 0; i < idx.size() - 1; ++i) {
            if (i == 0) cout << idx[0] + 1;
            else cout << " " << idx[i] - idx[i - 1];

            if (i == idx.size() - 2)
                cout << " " << n - idx[i] - 1;
        }  
    }
    return 0; 
}
