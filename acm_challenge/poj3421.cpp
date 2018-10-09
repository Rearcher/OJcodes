#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll factorial[21];
int factor[21], cnt, tot;

void init() {
    factorial[1] = 1;
    for (int i = 2; i <= 20; ++i)
        factorial[i] = factorial[i - 1] * i;
}

void factorize(int n) {
    cnt = tot = 0;
    int limit = sqrt(1.0 * n);
    for (int i = 2; i <= limit; ++i) {
        if (n % i == 0) {
            n /= i;
            factor[cnt++] = 1;
            tot++;

            while (n % i == 0) {
                n /= i;
                factor[cnt - 1] += 1;
                tot++;
            }
        }
    }
    if (n > 1) {
        factor[cnt++] = 1;
        tot++;
    }
} 

int main() {
    init();
    int n;
    while (cin >> n) {
        factorize(n);    
        ll res = factorial[tot];
        for (int i = 0; i < cnt; ++i)
            res /= factorial[factor[i]];
        cout << tot << " " << res << "\n";
    }
}