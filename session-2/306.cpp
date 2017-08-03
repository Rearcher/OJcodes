// 306. Additive Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; ++i) {
            for (int j = 1; j <= (num.size() - i) / 2; ++j) {
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }

private:
    bool check(string num1, string num2, string num) {
        if (num1.size() > 1 && num1[0] == '0') return false;
        if (num2.size() > 1 && num2[0] == '0') return false;

        string sum = add(num1, num2);
        if (sum == num) return true;

        if (num.size() < sum.size() || sum != num.substr(0, sum.size())) 
            return false;
        return check(num2, sum, num.substr(sum.size()));
    }

    string add(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0 ? (a[i--] - '0') : 0) + (j >= 0 ? (b[j--] - '0') : 0);
            result.push_back('0' + (sum % 10));
            carry = sum / 10; 
        }
        if (carry) result.push_back('0' + carry);
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution s;
    cout << s.isAdditiveNumber("199100199") << endl;
}