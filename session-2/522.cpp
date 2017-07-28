// 522. Longest Uncommon Subsequence II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [&](const string &a, const string &b) {
            return a.size() > b.size();
        });

        for (int i = 0; i < strs.size(); ++i) {
            int flag = 0;
            for (int j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) return strs[i].size();
        }

        return -1;
    }

private:
    // check whether a is a subsequence of b or not
    bool isSubsequence(string a, string b) {
        if (a.size() > b.size()) return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i == a.size();
    }
};

int main() {
    vector<string> strs{"aaa", "aaa", "aa"};
    Solution s;
    cout << s.findLUSlength(strs) << endl;
}