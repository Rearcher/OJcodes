// 365. Water and Jug Problem
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == z || y == z || x + y == z) return true;

        return z % gcd(x, y) == 0;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {

}