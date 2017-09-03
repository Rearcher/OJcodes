// 420. Strong Password Checker
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        int res = 0;
        int a = 1, A = 1, d = 1;
        vector<int> arr(s.size(), 0);

        for (int i = 0; i < s.size();) {
            if (islower(s[i])) a = 0;
            if (isupper(s[i])) A = 0;
            if (isdigit(s[i])) d = 0;

            int j = i;
            while (i < s.size() && s[j] == s[i]) i++;
            arr[j] = i - j;
        }

        int total = a + A + d;
        if (s.size() < 6) {
            res += total + max(0, 6 - ((int)s.size() + total));
        } else {
            int overLen = max(0, (int)s.size() - 20), leftOver = 0;
            res += overLen;

            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < s.size() && overLen > 0; ++i) {
                    if (arr[i] < 3 || arr[i] % 3 != k - 1) continue;
                    arr[i] -= min(overLen, k);
                    overLen -= k;
                }
            }

            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] >= 3 && overLen > 0) {
                    int need = arr[i] - 2;
                    arr[i] -= overLen;
                    overLen -= need;
                }

                if (arr[i] >= 3) leftOver += arr[i] / 3;
            }

            res += max(total, leftOver);
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.strongPasswordChecker("aaa111") << endl;
}