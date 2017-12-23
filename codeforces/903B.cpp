#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;

    vector<int> result;
    while (h2 > 0) {
        if (h1 > a2 || a1 >= h2) {
            result.push_back(1);
            h1 -= a2;
            h2 -= a1;
        } else {
            result.push_back(0);
            h1 += c1 - a2;
        }
    }
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] == 0) cout << "HEAL\n";
        else cout << "STRIKE\n";
    }
}