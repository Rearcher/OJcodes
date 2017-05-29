// 520. Detect Capital
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0) {
            return true;
        }

        int capital_cnt = 0;
        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                capital_cnt += 1;
            }
        }

        if (capital_cnt == word.size() || 
            capital_cnt == 0 || 
            (capital_cnt == 1 && word[0] >= 'A' && word[0] <= 'Z')) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;
    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("FlaG") << endl;
}