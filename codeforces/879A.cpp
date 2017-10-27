#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> doctors(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
        cin >> doctors[i].first >> doctors[i].second;
    
    int current = doctors[0].first;
    for (int i = 1; i < n; ++i) {
        while (doctors[i].first <= current)
            doctors[i].first += doctors[i].second;
        current = doctors[i].first;
    }

    cout << current << endl;
}