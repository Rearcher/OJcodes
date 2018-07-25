#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 100010;
typedef long long ll;

int N;
vector<int> x(MAX_N), y(MAX_N);
ll bit0[MAX_N], bit1[MAX_N];
vector<int> line[MAX_N];
bool visited[MAX_N];

ll sum(ll* bit, int i) {
    ll res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & (-i);
    }
    return res;
}

void add(ll* bit, int i, int x) {
    while (i <= MAX_N) {
        bit[i] += x;
        i += i & (-i);
    }
}

ll sum(int i) {
    return sum(bit1, i) * i + sum(bit0, i);
}

// range sum (from, to]
ll range_sum(int from, int to) {
    return sum(to) - sum(from);
}

// range add [from, to]
void range_add(int from, int to, ll x) {
    add(bit0, from, -x * (from - 1));
    add(bit1, from, x);
    add(bit0, to + 1, x * to);
    add(bit1, to + 1, -x);
}

int compress(vector<int>& p) {
    vector<int> temp(p);

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < N; ++i)
        p[i] = 1 + distance(temp.begin(), lower_bound(temp.begin(), temp.end(), p[i]));
    
    return temp.size();
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d%d", &x[i], &y[i]);

    int w = compress(x), h = compress(y);
    for (int i = 0; i < N; ++i)
        line[y[i]].push_back(x[i]);

    ll result = N;
    for (int y = 1; y <= h; ++y) {
        vector<int>& xs = line[y];
        sort(xs.begin(), xs.end());

        for (int i = 0; i < xs.size(); ++i) {
            int x = xs[i];
            ll s = range_sum(x - 1, x);

            if (visited[x]) result += s;
            else visited[x] = true;

            add(bit0, x, -s);

            if (i + 1 < xs.size()) {
                int next_x = xs[i + 1];
                if (x + 1 < next_x - 1) range_add(x + 1, next_x - 1, 1);
                else if (x + 1 == next_x - 1) add(bit0, x + 1, 1); 
            }
        }
    }
    printf("%lld\n", result);
}
