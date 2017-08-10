// 127. Word Ladder
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> next({beginWord}), prev({endWord});
        unordered_set<string> dict;
        for (string word : wordList) 
            dict.insert(word);
        if (!dict.count(endWord)) return 0;
        dict.erase(beginWord);
        dict.erase(endWord);

        int ladder = 1, len = beginWord.size();

        while (next.size() && prev.size()) {
            if (next.size() > prev.size())
                swap(next, prev);

            ladder += 1;
            unordered_set<string> temp;
            for (auto iter = next.begin(); iter != next.end(); iter++) {
                string word = *iter;
                for (int i = 0; i < len; ++i) {
                    char origin = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (prev.count(word))
                            return ladder;
                        if (dict.count(word)) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = origin;
                }
            }
            swap(next, temp);
        }

        return 0;
    }
};

int main() {
    vector<string> wordList{"hot","dot","dog","lot","log"};
    Solution s;
    cout << s.ladderLength("hit", "cog", wordList) << endl;
}