#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 25;

int W, H, res;
char room[N][N];
int visited[N][N];

void dfs(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) return;
    if (visited[x][y] || room[x][y] == '#') return;

    visited[x][y] = 1;
    res += 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    // freopen("input", "r", stdin);

    while (scanf("%d%d", &W, &H)) {
        if (W == 0 && H == 0) break;

        getchar();
        memset(visited, 0, sizeof(visited));
        res = 0;

        int x, y;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%c", &room[i][j]);
                if (room[i][j] == '@') x = i, y = j;
            }
            getchar();
        }

        dfs(x, y);
        printf("%d\n", res);
    }
    return 0;
}