// 806. Number of Lines To Write String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> result{1, 0};
        for (char c : S) {
            if (result[1] + widths[c - 'a'] > 100) {
                result[0] += 1;
                result[1] = widths[c - 'a'];
            } else {
                result[1] += widths[c - 'a'];
            }
        }
        return result;
    }
};