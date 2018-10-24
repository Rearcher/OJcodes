#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int k, n;
int a[1005], b[1005];
double x, y[1005];

bool valid() {
    for (int i = 0; i < n; ++i)
        y[i] = a[i] - x * b[i];
    sort(y, y + n);

    double s = 0;
    for (int i = k; i < n; ++i)
        s += y[i];
    return s >= 0;
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        if (n == 0 && k == 0) break;

        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        for (int i = 0; i < n; ++i) scanf("%d", b + i);

        double lo = 0, hi = 1;
        while (fabs(hi - lo) > 1e-5) {
            x = (lo + hi) / 2;
            if (valid()) lo = x;
            else hi = x;
        }
        x = x * 100;
        printf("%0.lf\n", x);
    }
}