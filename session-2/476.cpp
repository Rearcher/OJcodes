// 476. Number Complement
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int result = 0, multiplier = 1;
        while (num > 0) {
            result += multiplier * (1 - num & 1);
            multiplier *= 2;
            num >>= 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.findComplement(5) << endl;
    cout << s.findComplement(1) << endl;
}