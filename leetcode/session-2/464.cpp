// 464. Can I Win
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        unordered_map<int, bool> cache;
        return helper(maxChoosableInteger, desiredTotal, 0, cache);
    }

private:
    bool helper(int maxChoosableInteger, int desiredTotal, int status, unordered_map<int, bool>& cache) {
        if (desiredTotal <= 0) return false;
        if (cache.count(status)) return cache[status];

        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int mask = 1 << (i - 1);
            if (status & mask) continue;

            if (!helper(maxChoosableInteger, desiredTotal - i, status | mask, cache)) {
                cache[status] = true;
                return true;
            }
        }

        cache[status] = false;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.canIWin(10, 40) << endl;
}