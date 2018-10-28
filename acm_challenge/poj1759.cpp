#include <cstdio>
using namespace std;

int n;
double a, b, h[1005];

bool valid(double mid) {
    h[1] = mid;
    for (int i = 2; i < n; ++i) {
        h[i] = 2 * h[i - 1] - h[i - 2] + 2;
        if (h[i] < 0) return false;
    }
    b = h[n - 1];
    return true;
}

int main() {
    scanf("%d%lf", &n, &a);
    h[0] = a;

    double lb = 0, ub = 1010;
    while (ub - lb > 1e-6) {
        double mid = (lb + ub) / 2;
        if (valid(mid)) ub = mid;
        else lb = mid;
    }
    printf("%.2lf\n", b);
}