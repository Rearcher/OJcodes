#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int temp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp % 2) cnt++;
        else cnt--;
    }
    cout << abs(cnt) << "\n";
    
    return 0;
}