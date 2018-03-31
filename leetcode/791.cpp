// 791. Custom Sort String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(128, 0);
        for (char c : T) cnt[c]++;

        string result = "";
        for (char c : S) {
            if (cnt[c]) {
                result += string(cnt[c], c);
                cnt[c] = 0;
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c]) result += string(cnt[c], c);
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.customSortString("cba", "abcd") << "\n";
}