// 390. Elimination Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;

        int remain = n, step = 1, first = 1;
        while (remain > 1) {
            if (left || remain % 2 == 1) {
                first += step;
            }
            remain /= 2;
            step *= 2;
            left = !left;
        }

        return first;
    }
};

int main() {
    Solution s;
    cout << s.lastRemaining(10) << endl;
}