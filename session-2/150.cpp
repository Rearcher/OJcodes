// 150. Evaluate Reverse Polish Notation
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                st.push(stoi(token));
                continue;
            }

            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
        
            switch (token[0]) {
                case '+':
                    st.push(num2 + num1);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '*':
                    st.push(num2 * num1);
                    break;
                case '/':
                    st.push(num2 / num1);
            }
        }

        return st.top();
    }
};

int main() {
    Solution s;
    // vector<string> tokens{"2", "1", "+", "3", "*"};
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(tokens) << endl;
}