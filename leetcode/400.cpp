// 400. Nth Digit
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int level = 1;
        int level_cnt = (pow(10, level) - pow(10, level - 1)) * level;

        while (n - level_cnt > 0) {
            n -= level_cnt;
            level += 1;
            level_cnt = (pow(10, level) - pow(10, level - 1)) * level;
        }

        int order = (n % level == 0) ? (n / level) : (n / level + 1);
        int number = pow(10, level - 1) + order - 1;
        int digit_position = (n % level == 0) ? level : (n % level);

        digit_position = level - digit_position;
        return number / (int)pow(10, digit_position) % 10;
    }
};

int main() {
    Solution s;
    for (int i = 1; i <= 1000; ++i)
        cout << s.findNthDigit(i);
    // cout << s.findNthDigit(100) << endl;
}