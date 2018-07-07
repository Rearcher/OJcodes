// 862. Shortest Subarray with Sum at Least K
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), res = n + 1;
        vector<int> B(n + 1, 0);
        for (int i = 0; i < n; ++i) B[i + 1] += B[i] + A[i];

        deque<int> d;
        for (int i = 0; i < n + 1; ++i) {
            while (d.size() > 0 && B[i] - B[d.front()] >= K) {
                res = min(res, i - d.front());
                d.pop_front();
            }
            while (d.size() > 0 && B[i] < B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
};

int main() {
    vector<int> A{2, -1, 2};
    Solution s;
    cout << s.shortestSubarray(A, 3) << "\n";
}