#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    double t;

    scanf("%d", &n);
    priority_queue<double> pq;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &t);
        pq.push(t);
    }

    while (pq.size() > 1) {
        double m1 = pq.top(); pq.pop();
        double m2 = pq.top(); pq.pop();
        double m3 = 2 * sqrt(m1 * m2);
        pq.push(m3);
    }
    printf("%.3lf", pq.top());
}