// 140. Word Break II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_set<int> len;
        unordered_map<string, vector<string>> cache;
        for (string s : wordDict) {
            dict.insert(s);
            len.insert(s.size());
        }

        return dfs(dict, len, s, cache);
    }

private:
    vector<string> dfs(unordered_set<string>& dict, unordered_set<int>& len, string s, unordered_map<string, vector<string>>& cache) {
        if (cache.count(s)) return cache[s];

        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int j : len) {
            if (j > s.size()) continue;

            string str = s.substr(0, j);
            if (dict.count(str)) {
                vector<string> sub = dfs(dict, len, s.substr(j), cache);
                for (string s : sub) result.push_back(str + (s.empty() ? "" : " ") + s);
            }
        }
        cache[s] = result;
        return result;
    }
};

int main() {
    Solution s;
    vector<string> dict{"cat", "cats", "and", "sand", "dog"};
    vector<string> result = s.wordBreak("catsanddog", dict);

    for (string s : result) cout << s << "\n";
}