#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int sum[100005]; // sum[j]代表凑成j这个面值最多需要用多少当前的硬币
int f[100005];
int a[105], c[105];

int main() {
    
    int n, m;
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

        for (int i = 1; i <= m; ++i) f[i] = 0;
        f[0] = 1;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) sum[j] = 0;
            for (int j = a[i]; j <= m; ++j) {
                if (!f[j] && f[j - a[i]] && sum[j - a[i]] < c[i]) {
                    f[j] = 1;
                    sum[j] = sum[j - a[i]] + 1;
                    res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}