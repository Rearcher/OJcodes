// 792. Number of Matching Subsequences
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<const char*>> waiting(128, vector<const char*>());
        for (string& w : words)
            waiting[w[0]].push_back(w.c_str());

        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[*(++it)].push_back(it);
        }

        return waiting[0].size();
    }
};

int main() {
    Solution s;
    string S = "abcde";
    vector<string> words{"a", "bb", "acd", "ace"};
    cout << s.numMatchingSubseq(S, words) << "\n";
}