#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    stack<int> s;
    int i = n - 1;
    ll res = 0;
    while (i >= 0) {
        if (s.empty() || h[i] <= h[s.top()]) {
            res += (s.empty() ? n : s.top()) - i - 1;
            s.push(i);
            i -= 1;
        } else {
            s.pop();
        }
    }
    cout << res << endl;
}