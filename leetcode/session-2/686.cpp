// 686. Repeated String Match
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int a = A.size(), b = B.size();
        if (a > b) {
            for (int i = 0; i + b < a; ++i)
                if (A[i] == B[0] && A.substr(i, b) == B) return 1;

            A += A, a += a;
            for (int i = 0; i + b < a; ++i)
                if (A[i] == B[0] && A.substr(i, b) == B) return 2;

            return -1;
        }

        if (b % a == 0) {
            int flag = 0;
            for (int i = 0; i < b; i += a)
                if (B.substr(i, a) != A) {
                    flag = 1;
                    break;
                }
            if (flag == 0) return b / a;
        }

        int result = b / a + 1;
        string tmp(A);
        for (int i = 1; i < result; ++i) {
            A += tmp;
            a += tmp.size();
        }

        for (int i = 0; i + b < a; ++i) {
            if (A[i] == B[0] && A.substr(i, b) == B) return result;
        }
        return -1;
    }
};

int main() {
    Solution s;
    // cout << s.repeatedStringMatch("baaaabbbba", "bbaaaabbbbaabaaaabbbbaabaaaabbbbaabaaaabbbbaabaaaabbbbabbaaaabbbbabbaaaabbbbabbaaaabbbbabbaaaabbbbaa") << endl;
    // cout << s.repeatedStringMatch("aa", "a") << endl;
    // cout << s.repeatedStringMatch("abababaaba", "aabaaba") << endl;
    cout << s.repeatedStringMatch("babbbaabb", "babbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabbbabbbbaabb") << endl;
}