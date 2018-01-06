// 151. Reverse Words in a String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;

            if (idx != 0) s[idx++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ') s[idx++] = s[j++];
            reverse(s.begin() + idx - (j - i), s.begin() + idx);
            i = j;
        }
        s.erase(s.begin() + idx, s.end());
    }
};

int main() {
    Solution s;
    string str = "the sky is blue";
    s.reverseWords(str);
    cout << str << endl;
}