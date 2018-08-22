#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct COW {
    int s, e;
    bool operator < (const COW& other) const {
        return s < other.s;
    }
} COW;

COW cows[25010];

int main() {
    // freopen("input", "r", stdin);

    int n, t;
    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; ++i)
        scanf("%d%d", &cows[i].s, &cows[i].e);
    sort(cows, cows + n);

    int cnt = 0, end = 0, i = 0;
    while (end < t && i < n) {
        if (cows[i].s > end + 1) break;

        int temp = end;
        while (i < n && cows[i].s <= end + 1) {
            temp = max(temp, cows[i].e);
            i++;
        }
        end = temp;
        cnt += 1;
    }
    if (end < t) printf("-1\n");
    else printf("%d\n", cnt);

    return 0;
}