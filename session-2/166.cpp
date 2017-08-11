// 166. Fraction to Recurring Decimal
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        
        long long n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);

        res += to_string(n / d);
        if (n % d == 0) return res;

        res += ".";
        unordered_map<long long, int> map;
        for (long long remain = n % d; remain > 0; remain %= d) {
            if (map.count(remain)) {
                res.insert(map[remain], 1, '(');
                res += ')';
                break;
            }

            map[remain] = res.size();
            remain *= 10;
            res += to_string(remain / d);
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
}