#include <cstdio>
using namespace std;

int main() {
    int a[7];
    int t[4] = {0, 5, 3, 1};

    while (true) {
        int sum = 0;
        for (int i = 1; i < 7; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum == 0) break;

        int ans = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        
        int cnt_2 = a[4] * 5 + t[a[3] % 4];
        if (a[2] > cnt_2) ans += (a[2] - cnt_2 + 8) / 9;

        int cnt_1 = ans * 36 - a[6] * 36 - a[5] * 25 - a[4] * 16 - a[3] * 9 - a[2] * 4;
        if (a[1] > cnt_1) ans += (a[1] - cnt_1 + 35) / 36;
        printf("%d\n", ans);
    }
    return 0;
}