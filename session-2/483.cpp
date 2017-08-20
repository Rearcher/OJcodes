// 483. Smallest Good Base
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = (unsigned long long)stoll(n);
        for (int m = log(num) / log(2) + 1; m >= 2; --m) {
            unsigned long long base = pow(num, 1.0/(m-1)), sum = 1, factor = 1;
            for (int i = 1; i < m; ++i) {
                factor *= base;
                sum += factor;
            }
            if (sum == num) return to_string(base);
        }
        return to_string(num-1);
    }
};

int main() {
    Solution s;
    cout << s.smallestGoodBase("16035713712910627") << endl;
}