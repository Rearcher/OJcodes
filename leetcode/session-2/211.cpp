// 211. Add and Search Word - Data structure design
#include "leetcode.hpp"
using namespace std;

struct TrieNode {
    bool isWord;
    vector<TrieNode*> children;
    TrieNode() : isWord(false) {
        children = vector<TrieNode*>(26, nullptr);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        return search(word, root);
    }

private:
    bool search(string word, TrieNode* root) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (c != '.') {
                if (!cur->children[c - 'a']) return false;
                cur = cur->children[c - 'a'];
            } else {
                for (int j = 0; j < 26; ++j) {
                    if (cur->children[j] && search(word.substr(i+1), cur->children[j])) {
                        return true;
                    }
                }
                return false;
            }
        }
        return cur->isWord;
    }


    TrieNode* root;
};

int main() {
    WordDictionary dict;
    dict.addWord("mad");
    dict.addWord("pad");
    dict.addWord("bad");

    cout << dict.search(".a") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("b..") << endl;
    // cout << dict.search("bad") << endl;
    // cout << dict.search(".ad") << endl;
    // cout << dict.search("b..") << endl;
}