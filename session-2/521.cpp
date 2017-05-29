// 521. Longest Uncommon Subsequence I
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        }
        return max(a.length(), b.length());
    }
};

int main() {
    Solution s;
    string a = "aba", b = "cdc";
    cout << s.findLUSlength(a, b) << endl;
}