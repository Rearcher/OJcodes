// 739. Daily Temperatures
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (st.size() && temperatures[st.top()] <= temperatures[i]) st.pop();
            result[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);
    for (auto r : res) cout << r << " ";
    cout << "\n";
}