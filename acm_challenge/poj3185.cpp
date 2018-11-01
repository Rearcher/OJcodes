#include <cstdio>
#include <cstring>
using namespace std;

int cow[21], f[21], tmp[21];

int main() {
    for (int i = 0; i < 20; ++i) {
        scanf("%d", &cow[i]);
        tmp[i] = cow[i];
    }

    int cnt = 0;
    for (int i = 1; i < 20; ++i) {
        if (tmp[i - 1]) {
            tmp[i - 1] = 1 - tmp[i - 1];
            tmp[i] = 1 - tmp[i];
            if (i + 1 < 20) tmp[i + 1] = 1 - tmp[i + 1];
            cnt++;
        }
    }

    for (int i = 0; i < 20; ++i) tmp[i] = cow[i];
    int cnt2 = 1;
    tmp[0] = 1 - tmp[0];
    tmp[1] = 1 - tmp[1];
    for (int i = 1; i < 20; ++i) {
        if (tmp[i - 1]) {
            tmp[i - 1] = 1 - tmp[i - 1];
            tmp[i] = 1 - tmp[i];
            if (i + 1 < 20) tmp[i + 1] = 1 - tmp[i + 1];
            cnt2++;
        }
    }

    if (cnt2 < cnt) cnt = cnt2;
    printf("%d\n", cnt);
}