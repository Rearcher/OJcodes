// 402. Remove K Digits
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {        
        stack<char> st;
        for (int i = 0; i < num.size(); ++i) {
            char c = num[i];
            while (st.size() && st.top() > c && k > 0) {
                st.pop();
                k -= 1;
            }
            st.push(c);
        }

        while (k > 0 && st.size()) {
            st.pop();
            k--;
        }

        string result;
        while (st.size()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        int begin = 0;
        while (begin < result.size() && result[begin] == '0') begin++;
        if (begin >= result.size()) return "0";

        return result.substr(begin);
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("10", 3) << endl;
}