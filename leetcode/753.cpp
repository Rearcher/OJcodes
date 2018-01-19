// 753. Cracking the Safe
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        string cur = "";
        for (int i = 0; i < n; ++i) cur.push_back('0');

        unordered_set<string> used{cur};
        int len = pow(k, n) - 1 + n;
        dfs(n, k, len, cur, used);
        return cur;
    }

private:
    bool dfs(int n, int k, int len, string& cur, unordered_set<string>& used) {
        if (cur.size() == len) return true;

        string temp = cur.substr(cur.size() - n + 1);
        for (int i = 0; i < k; ++i) {
            temp.push_back('0' + i);
            if (used.count(temp)) continue;

            cur.push_back('0' + i);
            used.insert(temp);
            if (dfs(n, k, len, cur, used)) return true;
            cur.pop_back();
            used.erase(temp);
        }

        return false;
    } 
};

int main() {
    Solution s;
    cout << s.crackSafe(2, 3) << endl;
}