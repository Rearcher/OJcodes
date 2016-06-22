// Number of Islands
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {

        if (x < 0 || y < 0 || x >= n || y >= m) {
            return;
        }
        
        if (grid[x][y] == '1') {
            
            grid[x][y] = 'x';
            
            dfs(grid, x-1, y, n, m);
            dfs(grid, x, y-1, n, m);
            dfs(grid, x+1, y, n, m);
            dfs(grid, x, y+1, n, m);
        
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        
        int m = grid[0].size();
        if (!m) return 0;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    res += 1;
                }
            }
        }
        
        return res;
    }
};
