// 816. Ambiguous Coordinates
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for (int i = 1; i < S.size() - 2; ++i) {
            vector<string> left = helper(S.substr(1, i));
            vector<string> right = helper(S.substr(i + 1, S.size() - 2 - i));
            for (auto a : left)
                for (auto b : right)
                    res.push_back("(" + a + ", " + b + ")");
        }
        return res;
    }

private:
    vector<string> helper(string s) {
        int n = s.size();
        if (n == 0 || (n > 1 && s[0] == '0' && s[n - 1] == '0')) return {};
        if (n > 1 && s[0] == '0') return {"0." + s.substr(1)};
        if (n == 1 || s[n - 1] == '0') return {s};

        vector<string> res{s};
        for (int i = 1; i < n; ++i)
            res.push_back(s.substr(0, i) + '.' + s.substr(i));
        return res;
    }
};

int main() {
    Solution s;
    vector<string> res = s.ambiguousCoordinates("(123)");
    for (auto str : res) cout << str << " ";
    cout << "\n";
}