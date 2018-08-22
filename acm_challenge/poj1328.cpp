#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct point {
    double s, e;
    bool operator < (const point& rhs) const {
        return s < rhs.s;
    }
} point;

point p[1005];

int main() {
    int n, d, x, y, c = 0;
    while (scanf("%d%d", &n, &d)) {
        if (n == 0 && d == 0) break;

        c += 1;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            if (y > d) valid = false;

            double tmp = sqrt((double)(d * d) - y * y);
            p[i].s = x - tmp;
            p[i].e = x + tmp;
        }
        if (!valid) {
            printf("Case %d: -1\n", c);
            continue;
        }
        sort(p, p + n);

        int res = 1;
        point cur = p[0];
        for (int i = 1; i < n; ++i) {
            if (p[i].s > cur.e) {
                res += 1;
                cur = p[i];
            } else if (p[i].e <= cur.e) {
                cur = p[i];
            }
        }
        printf("Case %d: %d\n", c, res);
    }
    return 0;
}