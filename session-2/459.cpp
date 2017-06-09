// 459. Repeated Substring Pattern
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        bool result = false;

        for (int i = len / 2; i >= 1; i--) {
            if (len % i) {
                continue;
            }
            result = true;
            for (int j = 0; j < len - i; j += i) {
                if (s.substr(j, i) != s.substr(j + i, i)) {
                    result = false;
                    break;
                }
            } 
            if (result) {
                return result;
            } 
        }
    
        return result;
    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("ababab") << endl;
    cout << s.repeatedSubstringPattern("aba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabc") << endl;
    cout << s.repeatedSubstringPattern("bb") << endl;
}