// 844. Backspace String Compare
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        while (true) {
            int b = 0;
            while (i >= 0 && (b || S[i] == '#')) {
                b += S[i] == '#' ? 1 : -1;
                i--;
            }

            b = 0;
            while (j >= 0 && (b || T[j] == '#')) {
                b += T[j] == '#' ? 1 : -1;
                j--;
            }

            if (i < 0 || j < 0 || S[i] != T[j])
                return i == -1 && j == -1;

            i--, j--;
        }
    }
};

int main() {
    Solution s;
    string S = "bxj##tw";
    string T = "bxj###tw";

    cout << s.backspaceCompare(S, T) << "\n";
}