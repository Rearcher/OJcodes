#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
int x[MAX_N], n, m;

int valid(int num) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += upper_bound(x + i, x + n, x[i] + num) - (x + i) - 1;
    }
    return cnt >= m;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        m = (n * (n - 1) / 2 + 1)/ 2;
        for (int i = 0; i < n; ++i)
            scanf("%d", x + i);
        sort(x, x + n);

        int lb = 0, ub = x[n - 1] - x[0];
        while (lb < ub) {
            int mid = (lb + ub) / 2;
            if (valid(mid)) ub = mid;
            else lb = mid + 1;
        }
        printf("%d\n", ub);
    }
}