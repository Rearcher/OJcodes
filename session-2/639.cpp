// 639. Decode Ways II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), mod = pow(10, 9) + 7;
        long long f1 = 1, f2 = helper(s.substr(0, 1));
        for (int i = 1; i < n; ++i) {
            long long f3 = f2 * helper(s.substr(i, 1)) + f1 * helper(s.substr(i-1, 2));
            f1 = f2;
            f2 = f3 % mod;
        }
        return f2;
    }

private:
    long long helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0' ? 0 : 1;
        }

        if (s == "**") {
            return 15;
        } else if (s[1] == '*') {
            if (s[0] == '1') return 9;
            return s[0] == '2' ? 6 : 0;
        } else if (s[0] == '*') {
            return s[1] <= '6' ? 2 : 1;
        } else {
            return stoi(s) >= 10 && stoi(s) <= 26 ? 1 : 0;
        }
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("1*") << endl;
}