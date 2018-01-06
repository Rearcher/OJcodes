// 745. Prefix and Suffix Search
#include "leetcode.hpp"
using namespace std;

struct Trie {
    vector<int> words;
    vector<Trie*> children;

    Trie() {
        children = vector<Trie*>(26, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; ++i)
            if (children[i]) delete children[i];
    }

    void add(string& word, int begin, int index) {
        words.push_back(index);
        if (begin < word.size()) {
            if (!children[word[begin] - 'a'])
                children[word[begin] - 'a'] = new Trie();
            children[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }

    vector<int> find(string& prefix, int begin) {
        if (begin == prefix.size()) return words;
        if (!children[prefix[begin] - 'a']) return {};
        return children[prefix[begin] - 'a']->find(prefix, begin + 1);
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        forwardTree = new Trie();
        backwardTree = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            forwardTree->add(word, 0, i);
            reverse(word.begin(), word.end());
            backwardTree->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> v1 = forwardTree->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        vector<int> v2 = backwardTree->find(suffix, 0);

        int i = v1.size() - 1, j = v2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (v1[i] == v2[j]) return v1[i];
            else if (v1[i] > v2[j]) i--;
            else j--;
        }
        return -1;
    }

private:
    Trie* forwardTree, *backwardTree;
};

int main() {
    WordFilter s({"apple"});
    cout << s.f("", "e") << endl;
    cout << s.f("b", "") << endl;
}