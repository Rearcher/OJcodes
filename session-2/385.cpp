// 385. Mini Parser
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    NestedInteger deserialize(string s) {
        auto isnumber = [](char c) { return c == '-' || isdigit(c); };

        stack<NestedInteger> st;
        st.push(NestedInteger());

        int i = 0;
        while (i < s.size()) {
            if (isnumber(s[i])) {
                int j = i;
                while (j < s.size() && isnumber(s[j])) j++;
                st.top().add(NestedInteger(stoi(s.substr(i, j - i))));
                i = j;
            } else {
                if (s[i] == '[') {
                    st.push(NestedInteger());
                } else if (s[i] == ']') {
                    NestedInteger tmp = st.top();
                    st.pop();
                    st.top().add(tmp);
                }
                i++;
            }
        }

        return st.top();
    }
};

int main() {

}