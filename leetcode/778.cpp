// 778. Swim in Rising Water
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = max(grid[0][0], grid[n - 1][n - 1]);

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        visited[0][0] = true;

        vector<int> dir{-1, 0, 1, 0, -1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ans, 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i + 1];
                if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]) {
                    if (r == n - 1 && c == n - 1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    
}