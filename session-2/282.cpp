// 282. Expression Add Operators
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        dfs(result, num, "", 0, 0, target);
        return result;
    }

private:
    void dfs(vector<string>& result, string num, string expr, long long last, long long cur, int target) {
        if (num.empty()) {
            if (cur == target) result.push_back(expr);
            return;
        }

        for (int i = 1; i <= num.size(); ++i) {
            string temp = num.substr(0, i);
            if (temp.size() > 1 && temp[0] == '0') return;

            string nextNum = num.substr(i);
            if (expr.empty()) {
                dfs(result, nextNum, temp, stoll(temp), stoll(temp), target);
            } else {
                dfs(result, nextNum, expr + "+" + temp, stoll(temp), cur + stoll(temp), target);
                dfs(result, nextNum, expr + "-" + temp, -stoll(temp), cur - stoll(temp), target);
                dfs(result, nextNum, expr + "*" + temp, last * stoll(temp), cur - last + last * stoll(temp), target);
            }
        }
    }
};

int main() {
    Solution s;
    vector<string> result = s.addOperators("00", 0);
    for (auto s : result) cout << s << "\n";
}