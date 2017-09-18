// 678. Valid Parenthesis String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        return check(s, 0, 0);
    }

private:
    bool check(string s, int start, int count) {
        if (count < 0) return false;

        for (int i = start; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                count += 1;
            } else if (c == ')') {
                if (count <= 0) return false;
                count -= 1;
            } else if (c == '*') {
                return check(s, i + 1, count + 1) || check(s, i + 1, count - 1) || check(s, i + 1, count);
            }
        }

        return count == 0;
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("(*))") << endl;
}