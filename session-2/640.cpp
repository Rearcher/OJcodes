// 640. Solve the Equation
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int equal = equation.find('=');
        string left = equation.substr(0, equal);
        string right = equation.substr(equal + 1);

        // cout << left << " " << right << endl;
        pair<int, int> l = parse(left);
        pair<int, int> r = parse(right);

        // cout << l.first << " " << l.second << "\n";
        // cout << r.first << " " << r.second << "\n";
        pair<int, int> ans = {l.first - r.first, r.second - l.second};
        if (ans.first == 0) {
            return ans.second == 0 ? "Infinite solutions" : "No solution";
        }

        return "x=" + to_string(ans.second / ans.first);
    }

private:
    pair<int, int> parse(string s) {
        pair<int, int> result{0, 0};
        int index = 0, begin = 0;
        bool isNegative = false;

        if (s[0] == '-' || s[0] == '+') {
            isNegative = (s[0] == '-');
            index = begin = 1;
        }

        while (index <= s.size()) {
            if (index == s.size() || s[index] == '-' || s[index] == '+') {
                string tmp = s.substr(begin, index - begin);
                int number;

                if (tmp.back() == 'x') {
                    tmp.pop_back();
                    number = tmp.empty() ? 1 : stoi(tmp);
                    result.first += isNegative ? (-1 * number) : number;
                } else {
                    number = stoi(tmp);
                    result.second += isNegative ? (-1 * number) : number;
                }

                isNegative = (s[index] == '-');
                begin = index + 1;
            }
            index++;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.solveEquation("-x=-1") << endl;
}