#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int n;
double l, v;

typedef struct node {
    double p;
    string name;

    bool operator < (const node& rhs) const {
        return abs(p) < abs(rhs.p);
    }
} node;

node a[32010];

int main() {
    // freopen("input", "r", stdin);
    while (cin >> n) {
        if (n == 0) break;

        cin >> l >> v;
        char dir;
        for (int i = 0; i < n; ++i) {
            cin >> dir >> a[i].p >> a[i].name;
            if (dir == 'n' || dir == 'N')
                a[i].p = -a[i].p;
        }
        sort(a, a + n);

        double d = 0, tmp;
        int id = 0;
        for (int i = 0; i < n; ++i) {
            tmp = (a[i].p < 0 ? 0 : l) - a[i].p;
            if (tmp > d) {
                d = tmp;
                id = i;
            }
        }

        int cnt = 0;
        if (a[id].p > 0) {
            for (int i = id + 1; i < n; ++i) 
                if (a[i].p < 0) cnt++;
            id += cnt;
        } else {
            for (int i = 0; i < id; ++i)
                if (a[i].p > 0) cnt++;
            id -= cnt;
        }
        double res = d / v;
        cout << setw(13) << fixed << setprecision(2) << (int)(res * 100) / 100.0 << ' ' << a[id].name << endl;
    }

    return 0;
}