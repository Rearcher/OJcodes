#include <iostream>
using namespace std;

const int MAX_N = 100005;
int p[MAX_N], mark[MAX_N];

int find(int x) {
    while (!mark[x]) {
        x = p[x];
    }
    return x;
}

int main() {
    int n, q;
    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        for (int i = 1; i <= n; ++i) mark[i] = 0;
        mark[1] = 1;
        p[1] = 1;

        for (int i = 2; i <= n; ++i) cin >> p[i];
        long long res = 0;
        char c;
        int t;

        while (q--) {    
            cin >> c >> t;
            if (c == 'M') mark[t] = 1;
            else res += find(t);
        }
        cout << res << "\n";
    }
}