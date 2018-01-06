// 736. Parse Lisp Expression
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    Solution() {
        scope = vector<unordered_map<string, int>>();
        // scope.push_back(unordered_map<string, int>());
    }

    int evaluate(string expression) {
        scope.push_back(unordered_map<string, int>());
        int result = helper(expression);
        scope.pop_back();
        return result;
    }

private:
    vector<string> parse(string expression) {
        vector<string> result;
        int cnt = 0, i = 0;
        string temp = "";

        while (i < expression.size()) {
            int j = i;
            while (j < expression.size() && expression[j] != ' ') {
                if (expression[j] == '(') cnt++;
                else if (expression[j] == ')') cnt--;
                j++;
            }

            if (temp.size()) temp += " ";
            temp += expression.substr(i, j - i);
            if (cnt == 0) {
                result.push_back(string(temp));
                temp.clear();
            }

            i = j + 1;
        }

        if (temp.size()) result.push_back(temp);
        return result;
    }

    int helper(string expression) {
        if (expression[0] != '(') {
            if (isdigit(expression[0]) || expression[0] == '-') {
                return stoi(expression);
            }
            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope[i].count(expression)) {
                    return scope[i][expression];
                }
            }
        }

        int start = expression[1] == 'm' ? 6 : 5;
        vector<string> tokens = parse(expression.substr(start, expression.size() - start - 1));
        if (expression.substr(0, 4) == "(add") {
            return evaluate(tokens[0]) + evaluate(tokens[1]);
        } else if (expression.substr(0, 4) == "(mul") {
            return evaluate(tokens[0]) * evaluate(tokens[1]);
        } else {
            for (int j = 0; j < tokens.size() - 2; j += 2) {
                scope.back()[tokens[j]] = evaluate(tokens[j + 1]);
            }
            return evaluate(tokens.back());
        }
    }

    vector<unordered_map<string, int>> scope;
};

int main() {
    Solution s;
    // cout << s.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << endl;
    cout << s.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << endl;
}