// 214. Shortest Palindrome
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string temp(s);
        reverse(temp.begin(), temp.end());
        vector<int> table = getKMPTable(s + "#" + temp);

        string result = s.substr(table.back());
        reverse(result.begin(), result.end());
        return result + s;
    }

private:
    vector<int> getKMPTable(string s) {
        vector<int> result(s.size(), 0);

        int index = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[index] == s[i]) {
                result[i] = result[i-1] + 1;
                index += 1;
            } else {
                index = result[i-1];
                while (index > 0 && s[index] != s[i]) {
                    index = result[index-1];
                }

                if (s[index] == s[i]) index += 1;
                result[i] = index;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
}