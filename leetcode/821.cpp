// 821. Shortest Distance to a Character
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n, n);

        int pos = -n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) pos = i;
            res[i] = min(res[i], abs(i - pos));
        }
        return res;      
    }
};

int main() {
    Solution s;
    vector<int> result = s.shortestToChar("loveleetcode", 'e');
    for (auto i : result) cout << i << " ";
}