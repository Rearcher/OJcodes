#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sRoot = sqrt(n);
    int result = sRoot * 4;
    if (sRoot * sRoot == n) {
        cout << result << endl;
    } else {
        int left = n - sRoot * sRoot;
        if (left > sRoot) result += 4;
        else result += 2;

        cout << result << endl;
    }

    return 0;
}