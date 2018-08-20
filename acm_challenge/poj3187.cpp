#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[12][12];
int a[12], N, S;

int main() {
    cnt[1][1] = 1;

    for (int i = 2; i <= 10; ++i)
        for (int j = 1; j <= i; ++j)
            if (j == 1 || j == i) cnt[i][j] = 1;
            else cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];

    while (scanf("%d%d", &N, &S) == 2) {
        for (int i = 1; i <= N; ++i)
            a[i] = i;

        do {
            int sum = 0;
            for (int i = 1; i <= N; ++i)
                sum += a[i] * cnt[N][i];
            if (sum == S) break;
        } while (next_permutation(a + 1, a + N + 1));

        for (int i = 1; i <= N; ++i)
            printf("%d%c", a[i], i == N ? '\n' : ' ');
    }
    return 0;
}