// 498. Diagonal Traverse
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>{};

        int n = matrix[0].size();
        vector<pair<int, int>> direction{{-1, 1}, {1, -1}};
        vector<int> result;
        int x = 0, y = 0, dir = 0, diagonal_cnt = 1;
        while (true) {
            result.push_back(matrix[x][y]);
            if (result.size() == m * n) break;

            int num = matrix[x][y];

            int xNew = x + direction[dir].first;
            int yNew = y + direction[dir].second;
            if (xNew < 0 || xNew >= m || yNew < 0 || yNew >= n) {
                dir = (dir + 1) % 2;
                diagonal_cnt += 1;
                if (dir == 0) {
                    if (diagonal_cnt <= m) {
                        x = diagonal_cnt - 1;
                        y = 0;
                    } else {
                        x = m - 1;
                        y = diagonal_cnt - m;
                    }
                } else {
                    if (diagonal_cnt <= n) {
                        x = 0;
                        y = diagonal_cnt - 1;
                    } else {
                        x = diagonal_cnt - n;
                        y = n - 1;
                    }
                }
            } else {
                x = xNew;
                y = yNew;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};

    vector<int> result = s.findDiagonalOrder(matrix);
    for (auto r : result)
        cout << r << " ";
    cout << endl;
}