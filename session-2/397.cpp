// 397. Integer Replacement
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        long long num = n;
        while (num != 1) {
            if ((num & 1) == 0) { // n is even, just divide 2
                num >>= 1;
            } else if (num == 3 || ((num >> 1) & 1) == 0) { // n is 3 or the last 2 bits are 01, just reduce 1
                num--;
            } else { // others, increment 1
                num++;
            }
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.integerReplacement(2147483647) << endl;
}