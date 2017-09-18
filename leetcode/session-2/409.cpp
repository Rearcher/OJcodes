// 409. Longest Palindrome
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(52, 0);
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                cnt[c - 'a'] += 1;
            } else {
                cnt[c - 'A' + 26] += 1;
            }
        }

        int result = 0;
        bool has_single = false;
        for (int i = 0; i < 52; ++i) {
            if (cnt[i] == 0) {
                continue;
            }

            if (cnt[i] % 2 == 0) {
                result += cnt[i];
                cnt[i] = 0;
            } else {
                result += cnt[i] - 1;
                cnt[i] = 1;
                has_single = true;
            }
        }

        return has_single ? result + 1 : result;
    }
};

int main() {
    Solution s;
    string str = "ccc";
    cout << s.longestPalindrome(str) << endl;
}