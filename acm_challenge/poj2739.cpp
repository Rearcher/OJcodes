#include <cstdio>
#include <cstring>
using namespace std;

int p[10000], cnt;

void init() {
    int a[10005];
    memset(a, 1, sizeof(a));

    cnt = 0;
    a[0] = a[1] = 0;
    for (int i = 2; i < 10005; ++i) {
        if (a[i]) {
            p[cnt++] = i;
            for (int j = i * 2; j < 10005; j += i)
                if (a[j]) a[j] = 0;
        }
    }
}

void solve(int x) {
    int s = 0, e = 0, res = 0;
    int sum = p[s];
    while (s < cnt && e < cnt) {
        if (sum < x) {
            sum += p[++e];
        } else if (sum > x) {
            sum -= p[s++];
        } else {
            res += 1;
            s++;
            e = s;
            sum = p[s];
        }

        if (s > e) {
            e = s;
            sum = p[s];
        }
    }
    printf("%d\n", res);
}

int main() {
    init();

    int x;
    while (scanf("%d", &x)) {
        if (x == 0) break;
        solve(x);
    }
    return 0; 
}