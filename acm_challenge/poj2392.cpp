#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct block {
    int h, a, c;
    bool operator < (const block& rhs) const {
        return a < rhs.a;
    }
} block;

block b[405];
int num[40005], dp[40005];

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%d%d%d", &b[i].h, &b[i].a, &b[i].c);
    sort(b, b + k);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= b[i].a; ++j) num[j] = 0;
        for (int j = b[i].h; j <= b[i].a; ++j) {
            if (dp[j] < dp[j - b[i].h] + b[i].h && num[j - b[i].h] < b[i].c) {
                dp[j] = dp[j - b[i].h] + b[i].h;
                num[j] = num[j - b[i].h] + 1;
            }
        }
    }

    int res = -1;
    for (int i = b[k - 1].a; i >= 0; i--) {
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}