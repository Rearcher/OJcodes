#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
int v[MAX_N], w[MAX_N];

typedef struct node {
    double p;
    int id;
    bool operator < (const node& rhs) const {
        return p > rhs.p;
    }
} node;

node a[MAX_N];
int n, k;

bool valid(double x) {
    for (int i = 1; i <= n; ++i) {
        a[i].p = v[i] - x * w[i];
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);

    double s = 0;
    for (int i = 1; i <= k; ++i)
        s += a[i].p;
    return s >= 0;
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &v[i], &w[i]);
    
    double lb = 0, ub = 10000100, x;
    while (fabs(ub - lb) > 1e-6) {
        x = (lb + ub) / 2;
        if (valid(x)) lb = x;
        else ub = x;
    }
    
    for (int i = 1; i <= n; ++i) {
        a[i].p = v[i] - lb * w[i];
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; ++i) {
        printf("%d", a[i].id);
        printf("%c", i == k ? '\n' : ' ');
    }
}
