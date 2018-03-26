// 807. Max Increase to Keep City Skyline
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> left(n, 0);
        vector<int> top(m, 0);
        for (int i = 0; i < m; ++i)
            top[i] = *max_element(grid[i].begin(), grid[i].end());

        for (int j = 0; j < n; ++j) {
            vector<int> tmp;
            for (int i = 0; i < m; ++i)
                tmp.push_back(grid[i][j]);
            left[j] = *max_element(tmp.begin(), tmp.end());
        }

        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int limit = min(top[i], left[j]);
                sum += limit - grid[i][j];
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> grid{{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    Solution s;
    cout << s.maxIncreaseKeepingSkyline(grid) << "\n";
}