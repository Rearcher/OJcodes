// 467. Unique Substrings in Wraparound String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26, 0);
        int length = 0;

        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i-1] + 1 == p[i] || p[i-1] - p[i] == 25)) {
                length += 1;
            } else {
                length = 1;
            }
            count[p[i] - 'a'] = max(length, count[p[i] - 'a']);
        }

        return accumulate(count.begin(), count.end(), 0);
    }
};

int main() {
    Solution s;
    // cout << s.findSubstringInWraproundString("a") << endl;
    cout << s.findSubstringInWraproundString("cac") << endl;
    // cout << s.findSubstringInWraproundString("zab") << endl;
}