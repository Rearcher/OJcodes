#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int cnt = 0;
    unordered_set<int> s;
    for (int i = 0; i < x; ++i)
        s.insert(i);

    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp == x) cnt += 1;
        else if (tmp < x) s.erase(tmp);
    }
    cnt += s.size();

    cout << cnt << endl;
    return 0;
}