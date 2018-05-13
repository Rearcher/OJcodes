#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] > 1) {
            cnt[a[i]]--;
            continue;
        }
        res.push_back(a[i]);
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}