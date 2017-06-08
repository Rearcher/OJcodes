// 415. Add Strings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;

        while (i >= 0 && j >= 0) {
            int digit = (num1[i--] - '0') + (num2[j--] - '0') + carry;
            carry = digit / 10;
            digit %= 10;
            result.push_back(char('0' + digit));
        }

        while (i >= 0) {
            int digit = (num1[i--] - '0') + carry;
            carry = digit / 10;
            digit %= 10;
            result.push_back(char('0' + digit));
        }

        while (j >= 0) {
            int digit = (num2[j--] - '0') + carry;
            carry = digit / 10;
            digit %= 10;
            result.push_back('0' + digit);
        }

        if (carry > 0) {
            result.push_back('0' + carry);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    cout << s.addStrings("12323", "3378") << endl;
    cout << 12323 + 3378 << endl;
}