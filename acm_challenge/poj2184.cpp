#include <cstdio>
#include <algorithm>
using namespace std;

int s[105], f[105], dp[200010];

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d%d", &s[i], &f[i]);
    
    int inf = 0x3f3f3f3f, offset = 100000;
    for (int i = 0; i <= 200000; ++i) dp[i] = -inf;
    dp[offset] = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] > 0) {
            for (int j = 200000; j >= s[i]; --j)
                if (dp[j - s[i]] > -inf)
                    dp[j] =  max(dp[j], dp[j - s[i]] + f[i]);
        } else {
            for (int j = 0;  j - s[i] <= 200000; ++j)
                if (dp[j - s[i]] > -inf)
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        }
    }

    int res = 0;
    for (int i = offset; i <= 200000; ++i)
        if (dp[i] >= 0) res = max(res, dp[i] + i - offset);
    printf("%d\n", res);
}