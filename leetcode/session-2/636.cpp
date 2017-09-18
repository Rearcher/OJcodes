// 636. Exclusive Time of Functions
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;

        int prev = 0;
        for (string log : logs) {
            stringstream ss(log);
            string tmp;

            getline(ss, tmp, ':');
            int id = stoi(tmp);

            getline(ss, tmp, ':');
            bool start = (tmp == "start");

            getline(ss, tmp);
            int timePoint = stoi(tmp);

            if (start) {
                if (!st.empty()) result[st.top()] += timePoint - prev;
                st.push(id);
                prev = timePoint;
            } else {
                result[st.top()] += timePoint - prev + 1;
                st.pop();
                prev = timePoint + 1;
            }
        }

        return result;
    }
};

int main() {
    vector<string> logs{"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    Solution s;
    
    vector<int> result = s.exclusiveTime(2, logs);
    for (int i : result)
        cout << i << " ";
    cout << "\n";
}