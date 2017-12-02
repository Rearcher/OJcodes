#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int i = n - 1;
    int j = i - a[i] - 1, cnt = 1;
    i--;
    while (i >= 0) {
        if (i <= j) cnt++;
        j = min(j, i - 1 - a[i]);
        i--;
    }
    cout << cnt << endl;
    return 0;
}