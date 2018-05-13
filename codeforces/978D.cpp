#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (n <= 2) {
        cout << "0\n";
        return 0;
    } 

    int gap = b[1] - b[0];
    bool valid = true;
    for (int i = 2; i < n; ++i) {
        if (b[i] - b[i - 1] != gap) {
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << "0\n";
        return 0;
    }

    int res = INT_MAX;
    vector<int> change{-1, 0, 1};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            valid = true;

            vector<int> temp(b);
            temp[0] += change[i];
            temp[1] += change[j];
            gap = temp[1] - temp[0];
            int cur = abs(change[i]) + abs(change[j]);

            for (int i = 2; i < n; ++i) {
                int p = temp[i] - temp[i - 1];
                if (p == gap) continue;
                else if (p == gap - 1) {
                    temp[i] += 1;
                    cur++;
                } else if (p == gap + 1) {
                    temp[i] -= 1;
                    cur++;
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid) res = min(res, cur);
        }
    }

    if (res == INT_MAX) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}