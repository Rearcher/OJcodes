// 507. Perfect Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;

        int divisor = 2, sum = 1;
        unordered_map<int, bool> m;
        while (divisor <= sqrt(num)) {
            if (num % divisor == 0) {
                if (m.count(divisor) == 0) {
                    sum += divisor;
                    m[divisor] = true;
                }
                if (m.count(num / divisor) == 0) {
                    sum += num / divisor;
                    m[num / divisor] = true;
                }
            }
            divisor += 1;
        }
        return sum == num;
    }
};

int main() {
    Solution s;
    cout << s.checkPerfectNumber(99999996) << endl;
}