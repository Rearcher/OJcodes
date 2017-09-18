// 424. Longest Repeating Character Replacement
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int start = 0, maxCount = 0;
        int result = 0;

        for (int end = 0; end < s.size(); ++end) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            if (end - start + 1 - maxCount > k) {
                count[s[start++] - 'A']--;
            }
            result = max(result, end - start + 1);
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.characterReplacement("ABAB", 1) << endl;
}