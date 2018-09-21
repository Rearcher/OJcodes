#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

pair<int, int> a[100005];
long long pre[100005], suff[100005];

int main() {
    int n, c, f;
    scanf("%d%d%d", &n, &c, &f);
    for (int i = 0; i < c; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a, a + c);
    int len = n / 2;

    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < len; ++i) {
        pq.push(a[i].second);
        sum += a[i].second;
    }
    pre[len] = sum;
    for (int i = len; i + len < c; ++i) {
        int x = a[i].second;
        if (x < pq.top()) {
            sum -= pq.top() - x;
            pq.pop();
            pq.push(x);
        }
        pre[i + 1] = sum;
    }

    pq = priority_queue<int>();
    sum = 0;
    for (int i = c - 1; i > c - 1 - len; --i) {
        pq.push(a[i].second);
        sum += a[i].second;
    }
    suff[c - 1 - len] = sum;
    for (int i = c - 1 - len; i >= len; --i) {
        int x = a[i].second;
        if (x < pq.top()) {
            sum -= pq.top() - x;
            pq.pop();
            pq.push(x);
        }
        suff[i - 1] = sum;
    }

    int res = -1;
    for (int i = c - len - 1; i >= len; --i) {
        long long cur = suff[i] + pre[i] + a[i].second;
        if (cur <= f) {
            res = a[i].first;
            break;
        }
    }
    printf("%d\n", res);
}