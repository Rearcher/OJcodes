#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define lson idx * 2
#define rson idx * 2 + 1
#define inf 0x3f3f3f3f

ll tree[86401 * 4 + 5];

void build(int idx, int s, int e) {
    if (s > e) return;
    if (s == e) {
        tree[idx] = inf;
        return;
    }

    int m = (s + e) / 2;
    build(lson, s, m);
    build(rson, m + 1, e);
    tree[idx] = min(tree[lson], tree[rson]);
}

void update(int idx, int s, int e, int q, int val) {
    if (s == e) {
        tree[idx] = val;
        return;
    }

    int m = (s + e) / 2;
    if (q <= m) update(lson, s, m, q, val);
    else update(rson, m + 1, e, q, val);
    tree[idx] = min(tree[lson], tree[rson]);
}

ll query(int idx, int s, int e, int qs, int qe) {
    if (qs <= s && e <= qe) return tree[idx];

    int m = (s + e) / 2;
    ll res = inf;
    if (qs <= m) res = min(res, query(lson, s, m, qs, qe));
    if (qe > m) res = min(res, query(rson, m + 1, e, qs, qe));
    return res;
}

typedef struct Cow {
    int t1, t2, s;
    bool operator < (const Cow& rhs) const {
        return t1 < rhs.t1;
    }
} Cow;

Cow cow[10010];
int n, m, e;

int main() {
    // freopen("input", "r", stdin);
    cin >> n >> m >> e;
    for (int i = 0; i < n; ++i) {
        cin >> cow[i].t1 >> cow[i].t2 >> cow[i].s;
        cow[i].t1 += 2;
        cow[i].t2 += 2;
        cow[i].t1 -= m;
        cow[i].t2 -= m;
    }
    e = (e - m) + 2;
    m = 2;
    sort(cow, cow + n);

    build(1, 1, e);
    update(1, 1, e, 1, 0);
    for (int i = 0; i < n; ++i) {
        ll temp = query(1, 1, e, cow[i].t1 - 1, cow[i].t2 - 1) + cow[i].s;
        temp = min(query(1, 1, e, cow[i].t2, cow[i].t2), temp);
        update(1, 1, e, cow[i].t2, temp);
    }
    ll res = query(1, 1, e, e, e);
    if (res == inf) res = -1;
    cout << res << "\n";
}