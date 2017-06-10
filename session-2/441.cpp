// 441. Arranging Coins
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        unsigned int i = 1, sum = 0;
        while (true) {
            sum += i;
            if (sum > n) break;
            i += 1;
        }
        return i - 1;
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(5) << endl;
}