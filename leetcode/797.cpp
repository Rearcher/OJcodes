// 797. All Paths From Source to Target
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path{0};
        dfs(graph, path, result);
        return result;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        int start = path.back();
        if (start == graph.size() - 1) {
            result.push_back(vector<int>(path));
            return;
        }

        for (int i = 0; i < graph[start].size(); ++i) {
            path.push_back(graph[start][i]);
            dfs(graph, path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<vector<int>> graph{{1, 2}, {3}, {3}, {}};
    Solution s;

    vector<vector<int>> result = s.allPathsSourceTarget(graph);
    for (auto v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}