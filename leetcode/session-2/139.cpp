// 139. Word Break
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string word : wordDict)
            dict.insert(word);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    Solution s;
    vector<string> wordDict{"dog", "s", "gs"};

    cout << s.wordBreak("dogs", wordDict) << endl;
}