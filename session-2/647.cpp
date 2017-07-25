// 647. Palindromic Substrings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countSubStrings(string s) {
        int count = 0;
        for (int mid = 0; mid < s.size(); ++mid) {
            for (int j = 0; mid-j >= 0 && mid+j < s.size() && s[mid-j] == s[mid+j]; ++j) count++;
            for (int j = 0; mid-j-1 >= 0 && mid+j < s.size() && s[mid-j-1] == s[mid+j]; ++j) count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countSubStrings("aabb") << endl;
}