// 537. Complex Number Multiplication
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> r1 = parse(a);
        vector<int> r2 = parse(b);

        int first = r1[0] * r2[0] - r1[1] * r2[1];
        int second = r1[1] * r2[0] + r1[0] * r2[1];
        string result = "";

        result += to_string(first) + "+";
        result += to_string(second) + "i";

        return result;
    }

private:
    vector<int> parse(string s) {
        int plus = s.find('+');
        int a = 0, b = 0;
        bool isNegative = false;

        for (int i = 0; i < plus; ++i) {
            if (s[i] == '-') {
                isNegative = true;
                continue;
            }
            a = a * 10 + (s[i] - '0');
        }
        if (isNegative) a = -a;

        isNegative = false;
        for (int i = plus + 1; i < s.length() - 1; ++i) {
            if (s[i] == '-') {
                isNegative = true;
                continue;
            }
            b = b * 10 + (s[i] - '0');
        }
        if (isNegative) b = -b;

        return vector<int>{a, b};
    }
};

int main() {
    Solution s;
    cout << s.complexNumberMultiply("1+-1i", "1+-1i") << endl;
}