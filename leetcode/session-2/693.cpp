// 693. Binary Number with Alternating Bits
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        while (n > 0) {
            int cur = n % 2;
            if (cur == last) return false;

            n /= 2;
            last = cur;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.hasAlternatingBits(10) << endl;
}