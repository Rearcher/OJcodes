#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end(), [&](int a, int b){ return a > b; });

    vector<bool> used(n, false);
    int result = 0;
    while (true) {
        int i = 0, cur;
        while (i < n && used[i]) i++;
        if (i >= n) break;

        cur = a[i];
        used[i] = true;
        while (i < n) {
            if (!used[i] && a[i] < cur) {
                used[i] = true;
                cur = a[i];
            }
            i++;
        }
        result += 1;
    }
    cout << result << endl;
}