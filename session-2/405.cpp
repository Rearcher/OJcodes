// 405. Convert a Number to Hexadecimal
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        bool is_negative = num < 0;
        vector<int> result;

        unsigned int number = abs(num);
        while (number > 0) {
            int digit = number % 16;
            if (is_negative) {
                digit = 15 - digit;
            }
            result.push_back(digit);
            number /= 16;
        }

        if (is_negative) {
            while (result.size() < 8) {
                result.push_back(15);
            }

            int carry = 0;
            result[0] += 1;
            for (int i = 0; i < 8; ++i) {
                result[i] += carry;
                carry = result[i] / 16;
                result[i] %= 16;
            }
        }

        reverse(result.begin(), result.end());
        string str = "";
        for (int n : result) {
            if (n < 10) {
                str.push_back('0' + n);
            } else {
                str.push_back('a' + (n - 10));
            }
        }
        return str;
    }
};

int main() {
    Solution s;
    cout << s.toHex(26) << endl;
    cout << s.toHex(-1) << endl;
    cout << s.toHex(INT_MIN) << endl;
}