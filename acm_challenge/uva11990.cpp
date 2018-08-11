#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 200005;

int N, M, Del;
int st[20][MAX_N], bit[20][MAX_N];
int mp[MAX_N];
long long res;

void update(int* bit, int x, int v, int limit) {
    while (x <= limit) {
        bit[x] += v;
        x += x & (-x);
    }
}

int sum(int* bit, int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

void build(int idx, int s, int e, int depth) {
    for (int i = s; i <= e; ++i)
        st[depth][i] = st[depth - 1][i], bit[depth][i] = 0;

    if (s >= e) return;
    
    int m = (s + e) / 2;
    build(idx * 2, s, m, depth + 1);
    build(idx * 2 + 1, m + 1, e, depth + 1);
    sort(st[depth] + s, st[depth] + e + 1);
}

void queryPrefix(int idx, int s, int e, int depth, int qs, int qe, int qv) {
    if (qs <= s && e <= qe) {
        int pos = upper_bound(st[depth] + s, st[depth] + e + 1, qv) - st[depth];
        int pre = sum(bit[depth] + s - 1, pos - s);
        res -= (e - pos + 1) - (sum(bit[depth] + s - 1, e - s + 1) - pre);
        return;
    }

    if (s >= e) return;

    int m = (s + e) / 2;
    if (qs <= m) queryPrefix(idx * 2, s, m, depth + 1, qs, qe, qv);
    if (qe > m) queryPrefix(idx * 2 + 1, m + 1, e, depth + 1, qs, qe, qv);
}

void querySuffix(int idx, int s, int e, int depth, int qs, int qe, int qv) {
    if (qs <= s && e <= qe) {
        int pos = upper_bound(st[depth] + s, st[depth] + e + 1, qv) - st[depth];
        int pre = sum(bit[depth] + s - 1, pos - s);
        res -= (pos - s) - pre;
        return;
    }

    if (s >= e) return;

    int m = (s + e) / 2;
    if (qs <= m) querySuffix(idx * 2, s, m, depth + 1, qs, qe, qv);
    if (qe > m) querySuffix(idx * 2 + 1, m + 1, e, depth + 1, qs, qe, qv);
}

void update(int idx, int s, int e, int depth, int x, int v) {
    if (s == e) {
        update(bit[depth] + s - 1, 1, 1, e - s + 1);
        return;
    }

    if (s >= e) return;

    int m = (s + e) / 2;
    if (x <= m) update(idx * 2, s, m, depth + 1, x, v);
    else update(idx * 2 + 1, m + 1, e, depth + 1, x, v);

    int pos = lower_bound(st[depth] + s, st[depth] + e + 1, v) - st[depth];
    update(bit[depth] + s - 1, pos - s + 1, 1, e - s + 1);
}

int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        res = 0;

        for (int i = 1; i <= N; ++i) bit[0][i] = 0;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &st[0][i]);
            mp[st[0][i]] = i;
            res += i - 1 - sum(bit[0], st[0][i]);
            update(bit[0], st[0][i], 1, N);
        }
        build(1, 1, N, 1);

        while (M--) {
            scanf("%d", &Del);
            printf("%lld\n", res);
            queryPrefix(1, 1, N, 1, 1, mp[Del] - 1, Del);
            querySuffix(1, 1, N, 1, mp[Del] + 1, N, Del);
            update(1, 1, N, 1, mp[Del], Del);
        }
    }
    return 0;
}