#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, w;
    cin >> n >> w;

    long long t;
    long long low = 0, up = 0, sum = 0;
    while (n--) {
        cin >> t;
        sum += t;

        low = min(low, sum);
        up = max(up, sum);
    }

    long long x = abs(low);
    long long y = w - up;
    if (x <= y) cout << y - x + 1ll << "\n";
    else cout << "0\n";
}