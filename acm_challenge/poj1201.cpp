#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 50010;

struct Range {
    int a, b, c;
    bool operator < (const Range& other) const {
        return b < other.b;
    }
} range[MAX_N];
bool used[MAX_N];
int bit[MAX_N];

int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & (-i);
    }
    return res;
}

int range_sum(int a, int b) {
    return sum(b) - sum(a - 1);
}

void add(int i, int x) {
    while (i <= MAX_N) {
        bit[i] += x;
        i += i & (-i);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &range[i].a, &range[i].b, &range[i].c);
    sort(range, range + n);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int picked = range_sum(range[i].a + 1, range[i].b + 1);
        if (picked < range[i].c) {
            int remain = range[i].c - picked;
            res += remain;

            int idx = range[i].b;
            while (remain) {
                if (!used[idx]) {
                    used[idx] = true;
                    add(idx + 1, 1);
                    remain--;
                }
                idx--;
            }
        }
    }
    printf("%d\n", res);
}