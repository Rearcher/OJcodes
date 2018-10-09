#include <iostream>
#include <cstring>
using namespace std;

const int MAX_H = 1000002;
int is_h[MAX_H], cnt[MAX_H];

void init() {
    memset(is_h, 0, sizeof(is_h));
    for (int i = 5; i < MAX_H; i += 4) {
        for (int j = i; j < MAX_H; j += 4) {
            long long p = (long long)i * j;
            if (p >= MAX_H) break;
            if (is_h[i] == 0 && is_h[j] == 0) {
                is_h[p] = 1;
            } else {
                is_h[p] = -1;
            }
        }
    }
    cnt[1] = 0;
    for (int i = 5; i < MAX_H; i += 4)
        cnt[i] = cnt[i - 4] + (is_h[i] == 1 ? 1 : 0);
}

int main() {
    init();
    int h;
    while (cin >> h) {
        if (h == 0) break;
        cout << h << " " << cnt[h] << "\n";
    }
    return 0;
}