// 504. Base 7
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        bool is_negative = num < 0;
        num = abs(num);
        string res = "";

        while (num > 0) {
            char left = '0' + (num % 7);
            res.push_back(left);
            num /= 7;
        }
        if (is_negative) {
            res.push_back('-');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convertToBase7(100) << endl;
    cout << s.convertToBase7(-7) << endl;
}