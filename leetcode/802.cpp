// 802. Find Eventual Safe States
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> mark(n, 0);

        for (int i = 0; i < n; ++i)
            if (dfs(graph, i, mark))
                result.push_back(i);

        return result;
    }

private:
    bool dfs(vector<vector<int>>& graph, int start, vector<int>& mark) {
        if (mark[start] != 0) {
            return mark[start] == 1;
        }

        mark[start] = 2;
        for (int i = 0; i < graph[start].size(); ++i) {
            if (!dfs(graph, graph[start][i], mark)) return false;
        }
        mark[start] = 1;

        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> result = s.eventualSafeNodes(graph);

    for (auto i : result)
        cout << i << " ";
    cout << "\n";
}