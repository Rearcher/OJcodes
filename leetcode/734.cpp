// 734. Sentence Similarity
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        unordered_map<string, unordered_set<string>> m;
        for (auto p : pairs) m[p.first].insert(p.second);

        if (words1.size() != words2.size()) return false;
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (m[words1[i]].count(words2[i]) || m[words2[i]].count(words1[i])) continue;
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;
}