// 677. Map Sum Pairs
#include "leetcode.hpp"
using namespace std;

struct TrieNode {
    int cnt;
    vector<TrieNode*> next;

    TrieNode() {
        cnt = 0;
        next = vector<TrieNode*>(26, nullptr);
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        if (m.count(key)) {
            int oldVal = m[key];
            m[key] = val;
            val -= oldVal;
        } else {
            m[key] = val;
        }

        TrieNode* cur = root;
        for (char c : key) {
            int index = c - 'a';
            if (cur->next[index] == nullptr)
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
            cur->cnt += val;
        }
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (cur->next[index] == nullptr) return 0;
            cur = cur->next[index];
        }
        return cur->cnt;
    }

private:
    TrieNode* root;
    unordered_map<string, int> m;
};

int main() {
    MapSum m;
    m.insert("aa", 3);
    cout << m.sum("a") << endl;

    m.insert("aa", 2);
    cout << m.sum("a") << endl;
}