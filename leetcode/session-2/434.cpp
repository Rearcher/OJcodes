// 434. Number of Segments in a String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, i = 0;
        
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }

            if (i >= s.length()) break;

            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            cnt += 1;
        }

        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.countSegments("  ") << endl;
}