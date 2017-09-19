#include <iostream>
using namespace std;

int main() {
    int k, r;
    cin >> k;

    int maxRank = -1;
    for (int i = 0; i < k; ++i) {
        cin >> r;
        maxRank = max(r, maxRank);
    }

    int result = maxRank <= 25 ? 0 : maxRank - 25;
    cout << result << endl;
}