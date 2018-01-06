// 695. Max Area of Island
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 1) result = max(result, bfs(grid, i, j));
        return result;
    }

    int bfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] != 1) return 0;

        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();

            cnt += 1;

            if (tmp.first > 0 && grid[tmp.first-1][tmp.second] == 1) {
                q.push({tmp.first - 1, tmp.second});
                grid[tmp.first-1][tmp.second] = 2;
            }
            if (tmp.first + 1 < grid.size() && grid[tmp.first+1][tmp.second] == 1) {
                q.push({tmp.first + 1, tmp.second});
                grid[tmp.first+1][tmp.second] = 2;
            }
            if (tmp.second > 0 && grid[tmp.first][tmp.second-1] == 1) {
                q.push({tmp.first, tmp.second - 1});
                grid[tmp.first][tmp.second-1] = 2;
            }
            if (tmp.second + 1 < grid[0].size() && grid[tmp.first][tmp.second+1] == 1) {
                q.push({tmp.first, tmp.second + 1});
                grid[tmp.first][tmp.second+1] = 2;
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    cout << s.maxAreaOfIsland(grid) << endl;
}