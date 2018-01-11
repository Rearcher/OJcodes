// 752. Open the Lock
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited, next, q1, q2;
        string init = "0000";
        if (deads.find(init) != deads.end() || deads.find(target) != deads.end())
            return -1;

        q1.insert(init), q2.insert(target), visited.insert(init);
        int result = 0;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) swap(q1, q2);
            
            next.clear();
            for (auto s : q1) {
                vector<string> tmp = getNext(s);
                for (auto t : tmp) {
                    if (q2.find(t) != q2.end()) return result + 1;
                    if (visited.find(t) != visited.end()) continue;
                    if (deads.find(t) == deads.end()) {
                        next.insert(t);
                        visited.insert(t);
                    }
                }
            }

            swap(q1, next);
            result += 1;
        }

        return -1;
    }

private:
    vector<string> getNext(string s) {
        vector<string> result;
        for (int i = 0; i < s.size(); ++i) {
            string tmp = s;
            tmp[i] = (s[i] - '0' + 1) % 10 + '0';
            result.push_back(tmp);

            tmp[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            result.push_back(tmp);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> deads{"0201","0101","0102","1212","2002"};
    cout << s.openLock(deads, "0202") << endl;
}