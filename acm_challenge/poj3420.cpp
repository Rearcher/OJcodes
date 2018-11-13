#include <iostream>
#include <vector>
using namespace std;

int n, m;

typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &a, mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int k = 0; k < b.size(); ++k) {
            for (int j = 0; j < b[0].size(); ++j) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
    }
    return c;
}

mat pow(mat &a, ll n) {
    mat b(a.size(), vec(a[0].size()));
    for (int i = 0; i < a.size(); ++i)
        b[i][i] = 1;
    while (n > 0) {
        if (n & 1) b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}

int main() {
    while (cin >> n >> m) {
        if (!n && !m) break;
        mat A(5, vec(5));
        A[0][0] = A[0][1] = A[0][2] = A[0][3] = 1;
        A[1][0] = 1;
        A[2][0] = A[2][4] = 1;
        A[3][0] = 2; A[3][3] = 1;
        A[4][2] = 1;
        A = pow(A, n);
        cout << A[0][0] << "\n";
    }
    return 0;
}