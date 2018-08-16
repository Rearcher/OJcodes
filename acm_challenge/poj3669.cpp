#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 310;
const int dirs[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
int used[MAX_N][MAX_N];
int map[MAX_N][MAX_N];

typedef struct node {
    int x, y, t;

    node() {}

    node(int a, int b, int c) {
        x = a, y = b, t = c;
    }
} node;

node meteors[50010];

int main() {
    // freopen("input", "r", stdin);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &meteors[i].x, &meteors[i].y, &meteors[i].t);
    
    memset(map, 0x7f, sizeof(map));
    int max_time = 0;
    for (int i = 0; i < m; ++i) {
        max_time = max(max_time, meteors[i].t);
        for (int j = 0; j < 5; ++j) {
            int nx = meteors[i].x + dirs[j][0];
            int ny = meteors[i].y + dirs[j][1];
            if (nx >= 0 && ny >= 0 && map[nx][ny] > meteors[i].t)
                map[nx][ny] = meteors[i].t;
        }
    }

    if (map[0][0] == 0) {
        printf("-1\n");
        return 0;
    }

    memset(used, 0, sizeof(used));
    queue<node> q;
    q.push(node(0, 0, 0));
    used[0][0] = true;

    while (q.size()) {
        node cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dirs[i][0];
            int ny = cur.y + dirs[i][1];
            int nt = cur.t + 1;

            if (nx >= 0 && ny >= 0 && map[nx][ny] > nt && !used[nx][ny]) {
                used[nx][ny] = 1;
                if (map[nx][ny] > max_time) {
                    printf("%d\n", nt);
                    return 0;
                }
                q.push(node(nx, ny, nt));
            }
        }
    }
    printf("-1\n");
    return 0;
}