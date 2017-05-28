// 463. Island Perimeter
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = nrow > 0 ? grid[0].size() : 0;
        int result = 0;

        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                // up
                if (i == 0 || (i > 0 && grid[i-1][j] != 1)) {
                    result += 1;
                }
                // down
                if (i == nrow - 1 || (i + 1 < nrow && grid[i+1][j] != 1)) {
                    result += 1;
                }
                // left
                if (j == 0 || (j > 0 && grid[i][j-1] != 1)) {
                    result += 1;
                }
                // right
                if (j == ncol - 1 || (j + 1 < ncol && grid[i][j+1] != 1)) {
                    result += 1;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = vector<vector<int>>(4);
    grid[0] = vector<int>{0, 1, 0, 0};
    grid[1] = vector<int>{1, 1, 1, 0};
    grid[2] = vector<int>{0, 1, 0, 0};
    grid[3] = vector<int>{1, 1, 0, 0};
    cout << s.islandPerimeter(grid) << endl;
}