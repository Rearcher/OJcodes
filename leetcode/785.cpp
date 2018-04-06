// 785. Is Graph Bipartite?
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !bfs(graph, color, i))
                return false;
        }
        return true;
    }

private:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int s) {
        color[s] = 0;
        queue<int> q;
        q.push(s);

        while (q.size()) {
            int t = q.front();
            q.pop();

            for (int i = 0; i < graph[t].size(); ++i) {
                int next = graph[t][i];
                if (color[next] == -1) {
                    color[next] = 1 - color[t];
                    q.push(next);
                }

                if (color[next] == color[t]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

}