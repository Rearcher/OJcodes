#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n;

    vector<int> idx(n), score(n);
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
        cin >> a >> b >> c >> d;
        score[i] = a + b + c + d;
    }
    sort(idx.begin(), idx.end(), [&](int a, int b) { 
        if (score[a] == score[b])
            return a < b;
        return score[a] > score[b]; 
    });

    for (int i = 0; i < n; ++i) {
        if (idx[i] == 0) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}
