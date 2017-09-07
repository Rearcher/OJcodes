// 564. Find the Closest Palindrome
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        unordered_set<long long> candidates;
        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len-1) - 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string tmp = to_string(prefix + i);
            string cur = tmp + string(tmp.rbegin() + (len & 1), tmp.rend());
            candidates.insert(stoll(cur));
        }

        long long num = stoll(n), minDiff = LONG_MAX, diff, minval;
        candidates.erase(num);
        for (long long val : candidates) {
            diff = abs(num - val);
            if (diff < minDiff) {
                minDiff = diff;
                minval = val;
            } else if (diff == minDiff) {
                minval = min(val, minval);
            }
        }

        return to_string(minval);
    }
};

int main() {
    Solution s;
    cout << s.nearestPalindromic("1234567") << endl;
}