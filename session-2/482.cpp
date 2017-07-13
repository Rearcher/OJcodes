// 482. License Key Formatting
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string alphas = "";
        for (char c : S) {
            if (c != '-') {
                if (c >= 'a' && c <= 'z')
                    alphas.push_back(c - 32);
                else
                    alphas.push_back(c);
            }
        }

        string result = "";
        int left = alphas.size() % K;
        int begin = left > 0 ? left : K;
        result += alphas.substr(0, begin);
        while (begin < alphas.size()) {
            result += "-" + alphas.substr(begin, K);
            begin += K;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.licenseKeyFormatting("2-4A0r7-4k", 3) << endl;
}