// 210. Course Schedule II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisities) {
        vector<int> result;
        unordered_map<int, set<int>> edges;
        for (auto p : prerequisities) {
            int from = p.first, to = p.second;
            if (edges.count(from)) edges[from].insert(to);
            else edges[from] = {to};
        }

        vector<bool> visited(numCourses, false);
        while (result.size() < numCourses) {
            bool flag = false;
            for (int i = 0; i < numCourses; ++i) {
                if (!visited[i] && (!edges.count(i) || edges[i].empty())) {
                    result.push_back(i);
                    visited[i] = true;
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                return vector<int>{};
            }

            for (int i = 0; i < numCourses; ++i) {
                if (!visited[i] && edges.count(i) && edges[i].count(result.back()))
                    edges[i].erase(result.back());
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    // vector<pair<int, int>> prerequisities{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<pair<int, int>> prerequisities{{0, 1}, {1, 0}};

    vector<int> result = s.findOrder(2, prerequisities);
    for (int i : result) cout << i << " ";
    cout << "\n";
}