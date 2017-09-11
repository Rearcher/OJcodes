// 675. Cut Off Trees for Golf Event
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;

        vector<vector<int>> heights;
        for (int i = 0; i < forest.size(); ++i) 
            for (int j = 0; j < forest[i].size(); ++j)
                if (forest[i][j] > 1) heights.push_back({forest[i][j], i, j});
        sort(heights.begin(), heights.end());

        int res = 0;
        for (int i = 0, row = 0, col = 0; i < heights.size(); ++i) {
            int step = bfs(forest, row, col, heights[i][1], heights[i][2]);
            if (step == -1) return -1;

            res += step;
            row = heights[i][1];
            col = heights[i][2];
        }

        return res;
    }

private:
    int bfs(vector<vector<int>> &forest, int sx, int sy, int ex, int ey) {
        if (sx == ex && sy == ey) return 0;
        int nrow = forest.size(), ncol = forest[0].size(), step = 0;
        vector<vector<int>> visited(nrow, vector<int>(ncol, 0));        
        vector<int> dirs{-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;

        q.push({sx, sy});
        visited[sx][sy] = 1;
        while (!q.empty()) {
            step += 1;
            int len = q.size();
            while (len--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int r = row + dirs[i], c = col + dirs[i+1];
                    if (r < 0 || r >= nrow || c < 0 || c >= ncol || visited[r][c] == 1 || forest[r][c] == 0)
                        continue;
                    if (r == ex && c == ey) return step;
                    visited[r][c] = 1;
                    q.push({r, c});
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> forest{{1, 2, 3}, {0, 0, 4}, {7, 6, 5}};
    Solution s;
    cout << s.cutOffTree(forest) << endl;
}