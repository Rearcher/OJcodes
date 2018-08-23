#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);

    int c, y, m = 0x3fffffff;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &c, &y);
        m = min(m + s, c);
        res += m * y;
    }
    printf("%lld\n", res);
}