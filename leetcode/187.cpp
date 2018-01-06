// 187. Repeated DNA Sequences
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        int t = 0, i = 0, n = s.size();

        while (i < 9) {
            t = t << 3 | (s[i] & 7);
            i++;
        }

        vector<string> result;
        while (i < n) {
            t = (t << 3 & 0x3fffffff) | (s[i] & 7);
            m[t] += 1;

            if (m[t] == 2) result.push_back(s.substr(i - 9, 10));
            i++;
        }

        return result;
    }   
};

int main() {
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (string s : result) cout << s << " ";
    cout << "\n";
}