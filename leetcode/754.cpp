// 754. Reach a Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int step = 0, sum = 0;

        while (sum < target) {
            step++;
            sum += step;
        }
        while ((sum - target) % 2 != 0) {
            step++;
            sum += step;
        }

        return step;    
    }
};

int main() {

}