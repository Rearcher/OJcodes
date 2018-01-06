// 737. Sentence Similarity II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        unordered_map<string, unordered_set<string>> m;
        for (auto p : pairs) {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }

        if (words1.size() != words2.size()) return false;
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            unordered_set<string> visited;
            if (!isSimilar(words1[i], words2[i], m, visited)) return false;
        }

        return true;
    }

private:
    bool isSimilar(string word1, string word2, unordered_map<string, unordered_set<string>>& m, unordered_set<string>& visited) {
        visited.insert(word1);

        for (string w : m[word1]) {
            if (visited.count(w)) continue;
            if (w == word2) return true;
            visited.insert(w);
            if (isSimilar(w, word2, m, visited)) return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<string> words1{"great", "acting", "skills"};
    vector<string> words2{"fine", "drama", "talent"};
    vector<pair<string, string>> pairs{{"great", "good"}, {"fine", "good"}, {"acting", "drama"}, {"skills", "talent"}};
    cout << s.areSentencesSimilarTwo(words1, words2, pairs) << endl;
}