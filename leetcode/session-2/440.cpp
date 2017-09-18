// 440. K-th Smallest in Lexicographical Order
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1;

        while (k) {
            int steps = distance(n, cur, cur + 1);
            if (steps <= k) {
                cur += 1;
                k -= steps;
            } else {
                cur *= 10;
                k -= 1;
            }
        }

        return cur;
    }

private:
    int distance(int n, long long a, long long b) {
        int cnt = 0;
        while (a <= n) {
            cnt += min((long long)n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(13, 2) << endl;
}