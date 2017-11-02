#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    int n, a;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        heap.push(a);
    }

    long long result = 0;
    if (n % 2 == 0) heap.push(0);
    while (heap.size() > 1) {
        long long temp = 0;
        temp += heap.top(); heap.pop();
        temp += heap.top(); heap.pop();
        temp += heap.top(); heap.pop();
        heap.push(temp);
        result += temp;
    }

    cout << result << endl;
    return 0;
}