#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &a, mat &b) {
    mat c(a.size(), vec(b[0].size(), 0));
    for (ll i = 0; i < a.size(); ++i) {
        for (ll k = 0; k < b.size(); ++k) {
            if (a[i][k]) {
                for (ll j = 0; j < b[0].size(); ++j) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    return c;
}

mat pow(mat a, ll x) {
    mat b(a.size(), vec(a[0].size(), 0));
    for (ll i = 0; i < a.size(); ++i) b[i][i] = 1;
    while (x > 0) {
        if (x & 1) b = mul(b, a);
        a = mul(a, a);
        x >>= 1;
    }
    return b;
}

int main() {
    while (cin >> n >> m >> k) {
        if (n == 0 && m == 0 && k == 0) break;

        mat A(n + 1, vec(n + 1, 0));
        for (int i = 0; i <= n; ++i) A[i][i] = 1;

        char t;
        int a, b;
        for (int i = 0; i < k; ++i) {
            cin >> t;
            if (t == 'g') {
                cin >> a;
                A[0][a] += 1;
            } else if (t == 'e') {
                cin >> a;
                for (int i = 0; i <= n; ++i) A[i][a] = 0;
            } else if (t == 's') {
                cin >> a >> b;
                for (int i = 0; i <= n; ++i) swap(A[i][a], A[i][b]);
            }
        }

        A = pow(A, m);
        for (int i = 1; i <= n; ++i) {
            cout << A[0][i] << (i == n ? "\n" : " ");
        }
    }
    return 0;
}