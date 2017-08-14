// 660. Remove 9
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int newInteger(int n) {
        int res = 0, base = 1;

        while (n) {
            res += n % 9 * base;
            n /= 9;
            base *= 10;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.newInteger(100) << endl;
}