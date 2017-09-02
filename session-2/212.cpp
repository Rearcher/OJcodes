// 212. Word Search II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, root, result);
        return result;
    }

private:
    struct TrieNode {
        vector<TrieNode*> next;
        string word;

        TrieNode() {
            next = vector<TrieNode*>(26, nullptr);
            word = "";
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* p = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!p->next[idx]) p->next[idx] = new TrieNode();
                p = p->next[idx];
            }
            p->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || p->next[c - 'a'] == nullptr) return;

        p = p->next[c - 'a'];
        if (p->word != "") {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board{{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> words{"oath","pea","eat","rain"};
    vector<string> result = s.findWords(board, words);
    for (auto s : result) cout << s << " ";
}