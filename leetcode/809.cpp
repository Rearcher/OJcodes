// 809. Expressive Words
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int>> s;
        int i = 0;
        while (i < S.size()) {
            int cnt = 1;
            char c = S[i];
            while (i + 1 < S.size() && S[i + 1] == S[i]) {
                cnt += 1;
                i += 1;
            }
            i += 1;
            s.emplace_back(c, cnt);
        }

        int result = 0;
        for (string word : words) {
            int idx = 0;
            i = 0;

            while (i < word.size()) {
                int cnt = 1;
                char c = word[i];
                while (i + 1 < word.size() && word[i + 1] == word[i]) {
                    cnt += 1;
                    i += 1;
                }
                if (c != s[idx].first || (cnt < s[idx].second && s[idx].second < 3) || cnt > s[idx].second)
                    break;

                idx += 1;
                i += 1;
            }
            if (idx >= s.size()) result += 1;
        }

        return result;    
    }
};

int main() {
    Solution s;
    vector<string> words{"hello", "hi", "helo"};
    cout << s.expressiveWords("heeellooo", words) << "\n";
}