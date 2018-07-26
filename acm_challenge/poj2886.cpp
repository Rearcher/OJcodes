#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 500010;
int N, k, bit[MAX_N], num[MAX_N], f[MAX_N];
char names[MAX_N][12];

int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int sum(int from, int to) {
    return sum(to) - sum(from - 1);
}

void add(int i, int x) {
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

void init() {
    for (int i = 1; i <= MAX_N; i++)
        for (int j = 1; i * j <= MAX_N; j++) 
            f[i * j]++;
}

int binarySearch(int x) {
    int l = 1, r = N, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (sum(mid) >= x) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main() {
    
    init();
    while (~scanf("%d%d", &N, &k)) {
        memset(bit, 0, sizeof(bit));

        int maxF = 1;
        for (int i = 1; i <= N; ++i) {
            scanf("%s%d", names[i], &num[i]);
            maxF = max(maxF, f[i]);
            add(i, 1);
        }

        int cnt = 1, cur = k;
        while (true) {
            if (f[cnt] == maxF) {
                printf("%s %d\n", names[cur], f[cnt]);
                break;
            }

            int move = num[cur], left = N - cnt;
            if (move > 0) k = (k - 1 + move % left) % left;
            else k = ((k + move) % left + left) % left;
            if (k == 0) k = left;

            add(cur, -1);
            cur = binarySearch(k);
            cnt++;
        }
    }
    return 0;
}