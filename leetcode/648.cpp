// 648. Replace Words
#include "leetcode.hpp"
using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode* next[26];
    
    TrieNode() : isWord(false) {
        memset(next, 0, sizeof(next));
    }
};

void insert(TrieNode* root, string str) {
    TrieNode* cur = root;
    for (int i = 0; i < str.size(); ++i) {
        if (!cur->next[str[i] - 'a'])
            cur->next[str[i] - 'a'] = new TrieNode();
        cur = cur->next[str[i] - 'a'];
    }
    cur->isWord = true;
}

string search(TrieNode* root, string str) {
    TrieNode* cur = root;
    string result;

    for (int i = 0; i < str.size(); ++i) {
        if (cur->isWord) {
            return result;
        }

        result += str[i];        
        if (!cur->next[str[i] - 'a']) break;        
        cur = cur->next[str[i] - 'a'];
    }

    return str;
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root = new TrieNode();
        for (string s : dict)
            insert(root, s);

        stringstream ss1(sentence), ss2;
        vector<string> result;
        string word;
        while (ss1 >> word) {
            result.push_back(search(root, word));
        }

        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) ss2 << " ";
            ss2 << result[i];
        }
        return ss2.str();
    }
};

int main() {
    Solution s;
    vector<string> dict{"cat", "bat", "rat"};
    cout << s.replaceWords(dict, "the cattle was rattled by the battery");
}