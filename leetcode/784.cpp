// 784. Letter Case Permutation
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(S, result, 0);
        return result;
    }

private:
    void dfs(string S, vector<string>& result, int idx) {
        if (idx >= S.size()) {
            result.push_back(S);
            return;
        }

        char c = S[idx];

        dfs(S, result, idx + 1);
        if (c >= 'a' && c <= 'z') {
            S[idx] -= 32;
            dfs(S, result, idx + 1);
            S[idx] += 32;
        } else if (c >= 'A' && c <= 'Z') {
            S[idx] += 32;
            dfs(S, result, idx + 1);
            S[idx] -= 32;
        }
    }
};

int main() {
    Solution s;
    vector<string> result = s.letterCasePermutation("3z4");
    for (auto s : result) cout << s << "\n";
}