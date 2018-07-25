#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_N = 1001;
int bit[MAX_N][MAX_N], N;

int lowbit(int i) {
    return i & (-i);
}

int sum(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            res += bit[i][j];
    return res;
}

void add(int x, int y, int val) {
    for (int i = x; i <= N; i += lowbit(i))
        for (int j = y; j <= N; j += lowbit(j))
            bit[i][j] += val;
}

int main() {
    int x;
    scanf("%d", &x);

    while (x--) {
        int t, x1, y1, x2, y2;
        char c[10];
        scanf("%d%d", &N, &t);
        memset(bit, 0, sizeof(bit));

        while (t--) {
            scanf("%s", c);
            if (c[0] == 'C') {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(x1, y1, 1);
                add(x2 + 1, y1, 1);
                add(x1, y2 + 1, 1);
                add(x2 + 1, y2 + 1, 1);
            } else {
                scanf("%d%d", &x1, &y1);
                cout << sum(x1, y1) % 2 << "\n";
            }
        }
        if (x > 0) cout << "\n";
    }
}
