// 840. Magic Squares in Grid
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int nrow = grid.size(), ncol = grid[0].size();
        for (int i = 0; i + 3 <= nrow; ++i)
            for (int j = 0; j + 3 <= ncol; ++j)
                if (isMagic(grid, i, j)) cnt++;
        return cnt;
    }

private:
    bool isMagic(vector<vector<int>>& grid, int x, int y) {
        for (int i = x; i < x + 3; ++i)
            for (int j = y; j < y + 3; ++j)
                if (grid[i][j] < 1 || grid[i][j] > 9)
                    return false;
                    
        int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        for (int i = x + 1; i < x + 3; ++i)
            if (grid[i][y] + grid[i][y + 1] + grid[i][y + 2] != sum)
                return false;
        for (int j = y; j < y + 3; ++j)
            if (grid[x][j] + grid[x + 1][j] + grid[x + 2][j] != sum)
                return false;
        if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != sum)
            return false;
        if (grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2] != sum)
            return false;
        return true;
    }
};