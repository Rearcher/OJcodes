// 815. Bus Routes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                if (m.count(routes[i][j])) {
                    m[routes[i][j]].push_back(i);
                } else {
                    m[routes[i][j]] = {i};
                }
            }
        }

        unordered_set<int> visited;
        queue<int> q;
        q.push(S);

        int res = 0;
        while (q.size()) {
            int len = q.size();
            res += 1;
            for (int i = 0; i < len; ++i) {
                int cur = q.front();
                q.pop();
                for (int bus : m[cur]) {
                    if (visited.count(bus)) continue;
                    visited.insert(bus);
                    for (int j = 0; j < routes[bus].size(); ++j) {
                        if (routes[bus][j] == T) return res;
                        q.push(routes[bus][j]);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
    cout << s.numBusesToDestination(routes, 1, 6) << "\n";
}