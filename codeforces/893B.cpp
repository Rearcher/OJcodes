#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int limit = int(log(n) / log(2));
    int k = (limit + 1) / 2 + 1;
    while (k >= 1) {
        int ans = (pow(2, k) - 1) * pow(2, k - 1);
        if (ans <= n && n % ans == 0) {
            cout << ans << endl;
            return 0;
        }
        k--;
    }

    return 0;
}