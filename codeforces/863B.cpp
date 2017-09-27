#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, w;
    vector<int> weights;

    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        weights.push_back(w);
    }
    
    int result = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> v;
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) v.push_back(weights[k]);
            }
            sort(v.begin(), v.end());
            
            int temp = 0;
            for (int k = 0; k < v.size(); k += 2)
                temp += v[k + 1] - v[k];
            result = min(result, temp);
        }
    }
    cout << result << endl;
    return 0;
}