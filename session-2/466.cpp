// 466. Count The Repetitions
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(s2.size() + 1, 0);
        vector<int> nextIndex(s2.size() + 1, 0);
        int j = 0, cnt = 0;

        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == s2.size()) {
                        cnt += 1;
                        j = 0;
                    }
                }
            }

            repeatCount[k] = cnt;
            nextIndex[k] = j;
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] != j) continue;
                int prefixCount = repeatCount[start];
                int patternCount = (repeatCount[k] - repeatCount[start]) * (n1 - start) / (k - start);
                int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - repeatCount[start];
                return (prefixCount + patternCount + suffixCount) / n2;
            }
        }

        return repeatCount[n1] / n2;
    }
};

int main() {
    Solution s;
    cout << s.getMaxRepetitions("abc", 4, "ab", 2) << endl;
}