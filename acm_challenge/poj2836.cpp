#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef struct point {
    int x, y;
} point;

typedef struct rect {
    int area, cover;
} rect;

point ps[16];
rect rs[300];

int n, dp[1 << 16];

bool inside(int i, int j, int k) {
    int a = (ps[i].x - ps[k].x) * (ps[j].x - ps[k].x);
    int b = (ps[i].y - ps[k].y) * (ps[j].y - ps[k].y);
    return a <= 0 && b <= 0;
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i)
            cin >> ps[i].x >> ps[i].y;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                rect tmp;
                int h = abs(ps[i].x - ps[j].x);
                int w = abs(ps[i].y - ps[j].y);
                tmp.area = max(1, w) * max(1, h);
                tmp.cover = (1 << i) | (1 << j);
                for (int k = 0; k < n; ++k) {
                    if (inside(i, j, k)) tmp.cover |= (1 << k);
                }
                rs[cnt++] = tmp;
            }
        }

        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                dp[rs[i].cover | j] = min(dp[rs[i].cover | j], dp[j] + rs[i].area);
            }
        }
        cout << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}