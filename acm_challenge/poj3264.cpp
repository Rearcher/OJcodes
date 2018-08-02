#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int MAX_N = 50010;
vector<int> H(MAX_N);
vector<pair<int, int> > tree(MAX_N * 3);

void build(int idx, int s, int e) {
    if (s > e) return;

    if (s == e) {
        tree[idx].first = tree[idx].second = H[s];
        return;
    }

    int m = (s + e) / 2;
    build(2 * idx + 1, s, m);
    build(2 * idx + 2, m + 1, e);
    tree[idx].first = min(tree[2 * idx + 1].first, tree[2 * idx + 2].first);
    tree[idx].second = max(tree[2 * idx + 1].second, tree[2 * idx + 2].second);
}

int get_min(int idx, int s, int e, int qs, int qe) {
    if (qs > e || s > qe) return INT_MAX;
    if (s >= qs && e <= qe) return tree[idx].first;

    int m = (s + e) / 2;
    int left_min = get_min(2 * idx + 1, s, m, qs, qe);
    int right_min = get_min(2 * idx + 2, m + 1, e, qs, qe);
    return min(left_min, right_min);
}

int get_max(int idx, int s, int e, int qs, int qe) {
    if (qs > e || s > qe) return INT_MIN;
    if (s >= qs && e <= qe) return tree[idx].second;

    int m = (s + e) / 2;
    int left_max = get_max(2 * idx + 1, s, m, qs, qe);
    int right_max = get_max(2 * idx + 2, m + 1, e, qs, qe);
    return max(left_max, right_max);
}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 0; i < N; ++i)
        scanf("%d", &H[i]);
    build(0, 0, N - 1);

    for (int i = 0; i < Q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);

        l -= 1, r -= 1;
        int min_h = get_min(0, 0, N - 1, l, r);
        int max_h = get_max(0, 0, N - 1, l, r);
        printf("%d\n", max_h - min_h);
    }
    return 0;
}