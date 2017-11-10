#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) cnt++;
        else if (a[i] < a[i-1] && a[i] < a[i+1]) cnt++;
    }

    cout << cnt << endl;
}