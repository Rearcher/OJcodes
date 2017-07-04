// 481. Magical String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string str = "122";
        int i = 2;
        while (str.size() < n)
            str += string(str[i++] - '0', str.back() ^ 3);
        return count(str.begin(), str.begin() + n, '1');
    }
};

int main() {
    Solution s;
    cout << s.magicalString(6) << endl;
}