#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 20005;
int n, k;
int rk[MAX_N + 1], sa[MAX_N + 1], tmp[MAX_N + 1];

bool compare_sa(int i, int j) {
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    else {
        int ri = i + k <= n ? rk[i + k] : -1;
        int rj = j + k <= n ? rk[j + k] : -1;
        return ri < rj;
    }
}

void build_sa(string s) {
    n = s.length();
    for (int i = 0; i <= n; ++i) {
        sa[i] = i;
        rk[i] = i < n ? s[i] : -1;
    }

    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, compare_sa);

        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; ++i) {
            rk[i] = tmp[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A;
        cin >> A;
        int a_len = A.length();

        A = A + A + (char)('z' + 1);
        build_sa(A);

        int res = -1;
        for (int i = 0; i < a_len; ++i) {
            if (sa[i] < a_len) {
                res = sa[i] + 1;
                break;
            }
        }
        cout << res << "\n";
    }
}