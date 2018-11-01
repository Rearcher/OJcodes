#include <cstdio>
#include <cstring>
using namespace std;

int a[5][6], f[5][6];
int dx[5] = {-1, 0, 0, 0, 1};
int dy[5] = {0, -1, 0, 1, 0};

int q(int x, int y) {
    int s = a[x][y];
    for (int i = 0; i < 5; ++i) {
        int p = x + dx[i];
        int q = y + dy[i];
        if (p >= 0 && p < 5 && q >= 0 && q < 6)
            s += f[p][q];
    }
    return s & 1;
}

int solve() {
    int cnt = 0;
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (q(i - 1, j)) {
                f[i][j] = 1;
                cnt += 1;
            }
        }
    }

    for (int j = 0; j < 6; ++j)
        if (q(4, j)) return -1;
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int c = 1; c <= n; ++c) {        
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 6; ++j)
                scanf("%d", &a[i][j]);

        for (int i = 0; i < (1 << 6); ++i) {
            memset(f, 0, sizeof(f));

            for (int j = 0; j < 6; ++j)
                f[0][5 - j] = (i >> j) & 1;
            
            if (solve() >= 0) {
                printf("PUZZLE #%d\n", c);
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 6; ++j) {
                        if (j > 0) printf(" ");
                        printf("%d", f[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
    }
    return 0;
}