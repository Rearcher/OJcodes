// 621. Task Scheduler
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char c : tasks)
            count[c - 'A']++;

        priority_queue<int> pq;
        for (int c : count) {
            if (c) pq.push(c);
        }

        int result = 0, cycle = n + 1;
        while (!pq.empty()) {
            vector<int> tmp;
            int cur = 0;
            for (int i = 0; i < cycle; ++i) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    cur++;
                }
            }
            for (int t : tmp) {
                if (--t) {
                    pq.push(t);
                }
            }
            result += pq.empty() ? cur : cycle;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2) << endl;
}