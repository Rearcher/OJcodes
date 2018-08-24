#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node {
    int v, cnt;
    bool operator < (const node& rhs) const {
        return v > rhs.v;
    }
} node;

node coins[22];
int need[22];

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) 
        scanf("%d%d", &coins[i].v, &coins[i].cnt);

    sort(coins, coins + n);

    int ans = 0, idx = 0;
    while (idx < n && coins[idx].v >= c) {
        ans += coins[idx].cnt;
        idx++;
    }
    while (true) {
        memset(need, 0, sizeof(need));
        
        int sum = c;
        for (int i = idx; i < n; ++i) {
            if (sum > 0 && coins[i].cnt > 0) {
                int tmp = min(coins[i].cnt, sum / coins[i].v);
                if (tmp > 0) {
                    sum -= tmp * coins[i].v;
                    need[i] = tmp;
                }
            }
        }

        for (int i = n - 1; i >= idx; --i) {
            if (sum > 0 && coins[i].cnt > 0) {
                int tmp = min(coins[i].cnt - need[i], (sum + coins[i].v - 1) / coins[i].v);
                if (tmp > 0) {
                    sum -= tmp * coins[i].v;
                    need[i] += tmp;
                }
            }
        }

        if (sum > 0) break;
        int cur = 0x3fffffff;
        for (int i = idx; i < n; ++i)
            if (need[i] > 0) cur =  min(cur, coins[i].cnt / need[i]);
        ans += cur;
        for (int i = idx; i < n; ++i)
            if (need[i] > 0) coins[i].cnt -= cur * need[i];
    }
    printf("%d\n", ans);
}