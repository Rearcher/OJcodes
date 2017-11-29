#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    long long sum = 0;
    long long max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b >= max1) {
            max2 = max1;
            max1 = b;
        } else if (b > max2) {
            max2 = b;
        }
    }

    if (max1 + max2 >= sum) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}