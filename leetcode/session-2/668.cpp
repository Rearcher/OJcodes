// 668. Kth Smallest Number in Multiplication Table
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = count(m, n, mid);

            if (cnt >= k) high = mid;
            else low = mid + 1;
        }
        return high;
    }

private:
    int count(int m, int n, int val) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            cnt += min(n, val / i);
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(4, 6, 10);
}