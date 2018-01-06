// 472. Concatenated Words
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        unordered_set<string> dict;
        sort(words.begin(), words.end(), [&](string a, string b){ return a.size() < b.size(); });

        for (string word : words) {
            if (valid(word, dict)) result.push_back(word);
            dict.insert(word);
        }

        return result;
    }

private:
    bool valid(string word, unordered_set<string>& dict) {
        if (dict.empty()) return false;
        
        // dp[i] means word[0...i-1] can be formed by shorter words
        vector<bool> dp(word.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= word.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j]) continue;
                if (dict.count(word.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[word.size()];
    }
};

int main() {

}