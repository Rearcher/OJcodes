#include <cstdio>
#include <algorithm>
using namespace std;

int w, h, min_step;
int map[25][25];
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int step) {
    if (step >= 10 || step > min_step) return;

    for (int i = 0; i < 4; ++i) {
        int nx = x, ny = y;

        while (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            switch (map[nx][ny]) {
                case 0:
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                    break;
                case 3:
                    min_step = min(min_step, step + 1);
                    nx = -1;
                    break;
                case 1:
                    if (!(nx - dirs[i][0] == x && ny - dirs[i][1] == y)) {
                        map[nx][ny] = 0;
                        dfs(nx - dirs[i][0], ny - dirs[i][1], step + 1);
                        map[nx][ny] = 1;
                    }
                    nx = -1;
                    break;
                default:
                    break;
                
            }
        }
    }
}

int main() {
    while (scanf("%d%d", &w, &h)) {
        if (w == 0 && h == 0) break;

        int x, y;
        for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 2) x = i, y = j;
        }

        min_step = 11;
        map[x][y] = 0;
        dfs(x, y, 0);

        if (min_step > 10) min_step = -1;
        printf("%d\n", min_step);
    }
    return 0;
}