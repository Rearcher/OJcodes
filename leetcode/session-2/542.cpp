// 542. 01 Matrix
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = nrow > 0 ? matrix[0].size() : 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < dir.size(); ++i) {
                int x = cur.first + dir[i][0];
                int y = cur.second + dir[i][1];

                if (x < 0 || x >= nrow || y < 0 || y >= ncol || matrix[x][y] <= matrix[cur.first][cur.second] + 1)
                    continue;
                matrix[x][y] = matrix[cur.first][cur.second] + 1;
                q.push(make_pair(x, y));                
            }
        }

        return matrix;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = s.updateMatrix(matrix);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}