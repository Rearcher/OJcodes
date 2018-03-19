// 796. Rotate String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[0]) continue;

            string tmp = A.substr(i) + A.substr(0, i);
            if (tmp == B) return true;
        }      

        if (A.empty() && B.empty()) return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.rotateString("abcde", "cdeab") << endl;
    cout << s.rotateString("abcde", "abced") << endl;
}