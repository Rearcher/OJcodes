#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int map[5][5];
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
set<int> res;

void dfs(int x, int y, int step, int number) {
    if (step == 5) {
        res.insert(number);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            dfs(nx, ny, step + 1, number * 10 + map[nx][ny]);
    }
    return;
}

int main() {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            scanf("%d", &map[i][j]);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            dfs(i, j, 0, map[i][j]);

    printf("%d\n", (int)res.size());
}