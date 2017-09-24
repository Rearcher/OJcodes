// 682. Baseball Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> valid;

        for (string str : ops) {
            if (str == "+") {
                int top1 = valid.top();
                valid.pop();
                int newTop = top1 + valid.top();
                valid.push(top1);
                valid.push(newTop);
            } else if (str == "C") {
                valid.pop();
            } else if (str == "D") {
                valid.push(valid.top() * 2);
            } else {
                valid.push(stoi(str));
            }
        }

        int sum = 0;
        while (!valid.empty()) {
            sum += valid.top();
            valid.pop();
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<string> nums{"5","-2","4","C","D","9","+","+"};
    cout << s.calPoints(nums) << endl;
}