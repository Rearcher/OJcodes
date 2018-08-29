#include <iostream>
#include <cstdio>
using namespace std;

int dp[1010][32];
int a[1010], cnt1[1010], cnt2[1010];

int main() {
    
    int t, w;
    scanf("%d%d", &t, &w);

    for (int i = 1; i <= t; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            cnt1[i] = cnt1[i - 1] + 1;
            cnt2[i] = cnt2[i - 1];
        } else {
            cnt1[i] = cnt1[i - 1];
            cnt2[i] = cnt2[i - 1] + 1;
        }
    }

    int res = cnt1[t];
    for (int i = 1; i <= t; ++i) 
        dp[i][0] = cnt1[i] - cnt1[0];
    for (int i = 1; i <= t; ++i) {
        dp[i][1] = cnt1[i - 1] - cnt1[0];
        dp[i][1] += (a[i] == 2) ? 1 : 0;
        res = max(res, dp[i][1] + cnt2[t] - cnt2[i]);
    }
    
    for (int k = 2; k <= w; ++k) {
        for (int i = 1; i <= t; ++i) {
            int tmp = 0;
            for (int j = k - 1; j < i; ++j) {
                int cur = dp[j][k - 1];
                if ((k - 1) % 2 == 1) {
                    cur += cnt2[i - 1] - cnt2[j];
                    cur += (a[i] == 1) ? 1 : 0;
                } else {
                    cur += cnt1[i - 1] - cnt1[j];
                    cur += (a[i] == 2) ? 1 : 0;
                }
                tmp = max(tmp, cur);
            }
            dp[i][k] = tmp;

            int nres = dp[i][k];
            if (k % 2 == 1) nres += cnt2[t] - cnt2[i];
            else nres += cnt1[t] - cnt1[i];
            res = max(res, nres);
        }
    }
    printf("%d\n", res);
}