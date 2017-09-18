// 417. Pacific Atlantic Water Flow
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = nrow > 0 ? matrix[0].size() : 0;
        vector<pair<int, int>> result;
        vector<vector<bool>> pacific(nrow, vector<bool>(ncol, false));
        vector<vector<bool>> atlantic(nrow, vector<bool>(ncol, false));

        for (int i = 0; i < nrow; ++i) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, ncol-1);
        }
        for (int j = 0; j < ncol; ++j) {
            dfs(matrix, pacific, INT_MIN, 0, j);
            dfs(matrix, atlantic, INT_MIN, nrow-1, j);
        }

        for (int i = 0; i < nrow; ++i)
            for (int j = 0; j < ncol; ++j)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back(make_pair(i, j));
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int height, int x, int y) {
        int nrow = matrix.size();
        int ncol = nrow > 0 ? matrix[0].size() : 0;
        if (x < 0 || x >= nrow || y < 0 || y >= ncol || visited[x][y] || matrix[x][y] < height) return;

        visited[x][y] = true;
        dfs(matrix, visited, matrix[x][y], x-1, y);
        dfs(matrix, visited, matrix[x][y], x+1, y);
        dfs(matrix, visited, matrix[x][y], x, y+1);
        dfs(matrix, visited, matrix[x][y], x, y-1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    // vector<vector<int>> matrix{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

    vector<pair<int, int>> result = s.pacificAtlantic(matrix);
    for (pair<int, int> p : result) {
        cout << p.first << " " << p.second << "\n";
    }
}