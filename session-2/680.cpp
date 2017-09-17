// 680. Valid Palindrome II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }

            if (s[i+1] != s[j] && s[j-1] != s[i]) return false;
            return isPalindrome(s.substr(i+1, j-i)) || isPalindrome(s.substr(i, j-i));
        }

        return true;
    }

private:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("aba") << endl;
}