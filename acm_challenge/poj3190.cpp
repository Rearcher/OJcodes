#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct cow {
    int s, e, num;
    bool operator < (const cow& rhs) const {
        return e > rhs.e;
    }
} cow;

bool cmp(cow a, cow b) {
    if (a.s == b.s) return a.e < b.e;
    return a.s < b.s;
}

cow p[50010];
int stall[50010];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].s, &p[i].e);
        p[i].num = i + 1;
    }
    sort(p, p + n, cmp);

    int res = 1;
    priority_queue<cow> pq;
    pq.push(p[0]);
    stall[p[0].num] = res;

    for (int i = 1; i < n; ++i) {
        if (p[i].s > pq.top().e) {
            stall[p[i].num] = stall[pq.top().num];
            pq.pop();
        } else {
            stall[p[i].num] = ++res;
        }
        pq.push(p[i]);
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i) printf("%d\n", stall[i]);

    return 0;
}