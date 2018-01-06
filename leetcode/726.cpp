// 726. Number of Atoms
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> m;
        stack<map<string, int>> st;

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(m);
                m = map<string, int>();
                i++;
            } else if (formula[i] == ')') {
                int cnt = 0;
                i++;
                while (i < n && isdigit(formula[i])) {
                    cnt = cnt * 10 + (formula[i] - '0');
                    i++;
                }

                for (auto iter : m) {
                    st.top()[iter.first] += iter.second * cnt;
                }

                m = st.top();
                st.pop();
            } else {
                string name = "";
                name += formula[i++];
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    name += formula[i++];
                }

                int cnt = 0;
                while (i < n && isdigit(formula[i])) {
                    cnt = cnt * 10 + formula[i] - '0';
                    i++;
                }
                if (cnt == 0) cnt = 1;

                m[name] += cnt;
            }
        }

        string result = "";
        for (auto iter : m) {
            result += iter.first + (iter.second > 1 ? to_string(iter.second) : "");
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;
}