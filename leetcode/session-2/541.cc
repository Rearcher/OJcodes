// 541. Reverse String II
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string result = "";
        int i = 0, n = s.size();
        while (i < n) {
            string temp = "";
            temp = i + k <= n ? s.substr(i, k) : s.substr(i);
            reverse(temp.begin(), temp.end());
            result.append(string(temp));
            i = i + k <= n ? i + k : n;

            if (i >= n) break;
            temp = i + k <= n ? s.substr(i, k) : s.substr(i);
            result.append(string(temp));
            i = i + k <= n ? i + k : n;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.reverseStr("abcdefg", 3);
    return 0;
}