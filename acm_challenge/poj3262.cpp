#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node {
    int t, d;
    bool operator < (const node& rhs) const {
        return t * rhs.d < d * rhs.t;
    }
} node;

node cows[100010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &cows[i].t, &cows[i].d);
    sort(cows, cows + n);

    long long res = 0, waited = 0;
    for (int i = 0; i < n; ++i) {
        res += waited * cows[i].d;
        waited += 2 * cows[i].t;
    }
    printf("%lld\n", res);
}