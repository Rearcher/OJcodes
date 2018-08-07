#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 200020;
int tree[MAX_N * 2];
int x[MAX_N], x_comp[MAX_N], x_idx[MAX_N];
int y[MAX_N], y_comp[MAX_N], y_idx[MAX_N];
int wall_to_fly[MAX_N], wall_cnt[MAX_N], dis[MAX_N];
int x_cnt, y_cnt;

int wn, pn;
int *arr;
bool cmp(int a, int b) { return arr[a] < arr[b]; }

int query(int idx, int s, int e, int q) {
    if (tree[idx] != -2) return tree[idx];

    int mid = (s + e) >> 1;
    if (q <= mid) return query(idx * 2 + 1, s, mid, q);
    return query(idx * 2 + 2, mid + 1, e, q);
}

void update(int idx, int s, int e, int qs, int qe, int val) {
    if (qs <= s && e <= qe) {
        tree[idx] = val;
        return;
    }

    if (tree[idx] != -2) {
        tree[idx * 2 + 1] = tree[idx * 2 + 2] = tree[idx];
        tree[idx] = -2;
    }

    int mid = (s + e) >> 1;
    if (qs <= mid) update(idx * 2 + 1, s, mid, qs, qe, val);
    if (qe > mid) update(idx * 2 + 2, mid + 1, e, qs, qe, val);
}

void compress(int *x, int *comp, int *idx, int &c) {
    arr = x;
    for (int i = 0; i < pn; ++i) idx[i] = i;
    sort(idx, idx + pn, cmp);

    int cnt = 0;
    comp[idx[0]] = 0;
    for (int i = 1; i < pn; ++i) {
        if (x[idx[i]] != x[idx[i - 1]]) cnt++;
        comp[idx[i]] = cnt;
    }

    c = cnt;
}

void scan(int *y, int *x_comp, int i, int n) {
    if (i < wn) {
        int i2 = i ^ 1;
        if (x_comp[i2] >= x_comp[i])
            update(0, 0, n, x_comp[i], x_comp[i2], i / 2);
    } else {
        int t = query(0, 0, n, x_comp[i]);
        if (t != -1) {
            int d = min(abs(y[i] - y[2 * t]), abs(y[i] - y[2 * t + 1]));
            i -= wn;
            if (dis[i] == -1 || d < dis[i]) {
                dis[i] = d;
                wall_to_fly[i] = t;
            }
        }
    }
}

void fly(int *y, int *x_comp, int *idx, int n) {
    tree[0] = -1;
    for (int i = 0; i < pn; ++i) scan(y, x_comp, idx[i], n);
    tree[0] = -1;
    for (int i = pn - 1; i >= 0; --i) scan(y, x_comp, idx[i], n);
}

int main() {
    freopen("input", "r", stdin);

    memset(dis, -1, sizeof(dis));
    int n, m;
    scanf("%d%d", &n, &m);

    wn = 2 * n;
    pn = wn + m;
    for (int i = 0; i < pn; ++i)
        scanf("%d%d", x + i, y + i);
    compress(x, x_comp, x_idx, x_cnt);
    compress(y, y_comp, y_idx, y_cnt);
    fly(y, x_comp, y_idx, x_cnt);
    fly(x, y_comp, x_idx, y_cnt);

    for (int i = 0; i < m; ++i) wall_cnt[wall_to_fly[i]]++;
    for (int i = 0; i < n; ++i) printf("%d\n", wall_cnt[i]);
}