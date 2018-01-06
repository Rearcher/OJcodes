// 676. Implement Magic Dictionary
#include "leetcode.hpp"
using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        this->lens.clear();
        this->dict.clear();
        for (string s : dict) {
            this->dict.insert(s);
            this->lens.insert(s.size());
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if (!lens.count(word.size())) return false;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            for (int j = 0; j < 26; ++j) {
                if (c == 'a' + j) continue;
                word[i] = 'a' + j;
                if (dict.count(word)) return true;
            }
            word[i] = c;
        }
        return false;
    }

private:
    unordered_set<int> lens;
    unordered_set<string> dict;
};

int main() {
    
}