// 771. Jewels and Stones
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> cnt(52, 0);
        for (char c : J) {
            if (c >= 'a' && c <= 'z') {
                cnt[c - 'a'] = 1;
            } else if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A' + 26] = 1;
            }
        }

        int result = 0;
        for (char c : S) {
            int index = -1;
            if (c >= 'a' && c <= 'z') {
                index = c - 'a';
            } else if (c >= 'A' && c <= 'Z') {
                index = c - 'A' + 26;
            }

            if (cnt[index]) result += 1;
        }      

        return result;
    }
};