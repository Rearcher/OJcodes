// 546. Remove Boxes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int cache[100][100][100] = {0};
        return dfs(boxes, cache, 0, n - 1, 0);
    }

private:
    int dfs(vector<int>& boxes, int cache[100][100][100], int l, int r, int k) {
        if (l > r) return 0;
        if (cache[l][r][k]) return cache[l][r][k];

        while (r > l && boxes[r] == boxes[r-1]) {
            r--;
            k++;
        }
        cache[l][r][k] = dfs(boxes, cache, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                cache[l][r][k] = max(cache[l][r][k], dfs(boxes, cache, l, i, k+1) + dfs(boxes, cache, i+1, r-1, 0));
            }
        }

        return cache[l][r][k];
    }
};

int main() {
    vector<int> boxes{1, 3, 2, 2, 2, 3, 4, 3, 1};
    Solution s;
    cout << s.removeBoxes(boxes) << endl;
}