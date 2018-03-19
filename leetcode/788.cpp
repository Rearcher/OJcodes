// 788. Rotated Digits
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            int num = i;
            bool valid = true, good = false;
            while (num) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    valid = false;
                    break;
                }

                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    good = true;
                }
                num /= 10;
            }

            if (valid && good) cnt += 1;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.rotatedDigits(857) << endl;
}