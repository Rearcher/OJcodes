// 633. Sum of Square Numbers
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;

        int sRoot = sqrt(c);
        if (c == sRoot * sRoot) return true;

        while (sRoot > 0) {
            int left = c - sRoot * sRoot;
            if (isSquare(left)) return true;
            sRoot--;
        }

        return false;
    }

private:
    bool isSquare(int c) {
        int sRoot = sqrt(c);
        if (c == sRoot * sRoot) return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(11) << endl;
}