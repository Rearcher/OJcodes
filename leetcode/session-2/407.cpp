// 407. Trapping Rain Water
#include "leetcode.hpp"
using namespace std;

struct Cell {
    int x, y, height;
    Cell(int a, int b, int c) : x(a), y(b), height(c) {}
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int nrow = heightMap.size();
        int ncol = nrow > 0 ? heightMap[0].size() : 0;
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));

        auto cmp = [&](Cell a, Cell b) {return a.height > b.height;};
        priority_queue<Cell, vector<Cell>, decltype(cmp)> minHeap(cmp);
        for (int i = 0; i < nrow; ++i) {
            visited[i][0] = true;
            visited[i][ncol-1] = true;
            minHeap.push(Cell(i, 0, heightMap[i][0]));
            minHeap.push(Cell(i, ncol-1, heightMap[i][ncol-1]));
        }
        for (int j = 1; j < ncol-1; ++j) {
            visited[0][j] = true;
            visited[nrow-1][j] = true;
            minHeap.push(Cell(0, j, heightMap[0][j]));
            minHeap.push(Cell(nrow-1, j, heightMap[nrow-1][j]));
        }
        
        int result = 0;
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (minHeap.size()) {
            Cell cell = minHeap.top();
            minHeap.pop();

            for (vector<int> dir : dirs) {
                int x = cell.x + dir[0], y = cell.y + dir[1];
                if (x > 0 && x < nrow && y > 0 && y < ncol && !visited[x][y]) {
                    visited[x][y] = true;
                    result += max(0, cell.height - heightMap[x][y]);
                    minHeap.push(Cell(x, y, max(cell.height, heightMap[x][y])));
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> heightMap{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    cout << s.trapRainWater(heightMap) << endl;
}