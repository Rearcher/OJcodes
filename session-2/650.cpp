// 650. 2 Keys Board
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;

        int count = 1, increment = 1, already = 1;
        int left = n - already;
        while (left > 0) {
            if (left == increment) {
                count += 1;
                break;
            }

            if (increment != already && left % already == 0) {
                increment = already;
                left -= increment;
                already += increment;
                count += 2;
            } else {
                left -= increment;
                already += increment;
                count += 1;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    cout << s.minSteps(3) << endl;
    cout << s.minSteps(4) << endl;
    cout << s.minSteps(5) << endl;
    cout << s.minSteps(6) << endl;
    cout << s.minSteps(1000) << endl;
}