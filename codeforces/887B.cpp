#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<unordered_set<int>> has(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> t;
            has[i].insert(t);
        }
    }

    for (int i = 1; i < pow(10, n); ++i) {
        unordered_set<int> t;
        int num = i, length = 0;
        while (num > 0) {
            int digit = num % 10;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (has[i].count(digit)) {
                    t.insert(i);
                    flag = false;
                }
            }
            if (flag) {
                cout << i - 1 << endl;
                return 0;
            }
            length++;
            num /= 10;
        }

        if (t.size() < length) {
            cout << i - 1 << endl;
            return 0;
        }
    }

    return 0;
}