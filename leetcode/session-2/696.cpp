// 696. Count Binary Substrings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] == '0' && s[i+1] == '1') {
                int left = i, right = i + 1;
                while (left >= 0 && s[left] == '0' && right < s.size() && s[right] == '1') 
                    cnt++, left--, right++;
            } else if (s[i] == '1' && s[i+1] == '0') {
                int left = i, right = i + 1;
                while (left >= 0 && s[left] == '1' && right < s.size() && s[right] == '0') 
                    cnt++, left--, right++;
            }
        }

        return cnt;
    }
};