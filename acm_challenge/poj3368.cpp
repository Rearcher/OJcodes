#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 100010;

struct Node {
    int left, right;
    int lmax, cmax, rmax;
} tree[MAX_N * 4];
int a[MAX_N];

void build(int idx, int s, int e) {
    tree[idx].left = s;
    tree[idx].right = e;

    if (s == e) {
        tree[idx].lmax = tree[idx].cmax = tree[idx].rmax = 1;
        return;
    }

    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);

    int temp = 0;
    if (a[tree[idx * 2 + 1].right] == a[tree[idx * 2 + 2].left])
        temp = tree[idx * 2 + 1].rmax + tree[idx * 2 + 2].lmax;
    tree[idx].cmax = max(max(tree[idx * 2 + 1].cmax, tree[idx * 2 + 2].cmax), temp);

    tree[idx].lmax = tree[idx * 2 + 1].lmax;
    if (tree[idx * 2 + 1].lmax == mid - s + 1 && a[tree[idx * 2 + 1].right] == a[tree[idx * 2 + 2].left])
        tree[idx].lmax += tree[idx * 2 + 2].lmax;

    tree[idx].rmax = tree[idx * 2 + 2].rmax;
    if (tree[idx * 2 + 2].rmax == e - mid && a[tree[idx * 2 + 1].right] == a[tree[idx * 2 + 2].left])
        tree[idx].rmax += tree[idx * 2 + 1].rmax;
}

int query(int idx, int qs, int qe) {
    if (tree[idx].left == qs && tree[idx].right == qe)
        return tree[idx].cmax;

    int mid = (tree[idx].left + tree[idx].right) / 2;
    if (qe <= mid) return query(idx * 2 + 1, qs, qe);
    else if (qs > mid) return query(idx * 2 + 2, qs, qe);

    int a1 = query(idx * 2 + 1, qs, mid);
    int a2 = query(idx * 2 + 2, mid + 1, qe);
    int a3 = 0;
    if (a[tree[idx * 2 + 1].right] == a[tree[idx * 2 + 2].left])
        a3 = min(tree[idx * 2 + 1].rmax, mid - qs + 1) + min(tree[idx * 2 + 2].lmax, qe - mid);
    return max(max(a1, a2), a3);
}

int main() {
    // freopen("input", "r", stdin);

    int n, q, s, e;
    while (~scanf("%d", &n)) {
        if (n == 0) break;
        scanf("%d", &q);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        build(0, 0, n - 1);

        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &s, &e);
            printf("%d\n", query(0, s - 1, e - 1));
        }
    }
    return 0;
}