// 838. Push Dominoes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        string res = "";

        for (int i = 0, j = 1; j < dominoes.size(); ++j) {
            if (dominoes[j] == '.') continue;

            int cnt = j - i - 1;
            if (i > 0) res += dominoes[i];
            if (dominoes[i] == dominoes[j]) res += string(cnt, dominoes[j]);
            else if (dominoes[i] == 'L' && dominoes[j] == 'R') res += string(cnt, '.');
            else res += string(cnt / 2, 'R') + string(cnt % 2, '.') + string(cnt / 2, 'L');
            i = j;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.pushDominoes(".L.R...LR..L..") << endl;
}