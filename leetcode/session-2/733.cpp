// 733. Flood Fill
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int nrow = image.size();
        int ncol = image[0].size();
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        helper(image, visited, sr, sc, image[sr][sc], newColor);
        return image;
    }

private:
    void helper(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int color, int newColor) {
        int nrow = image.size();
        int ncol = image[0].size();

        if (sr < 0 || sr >= nrow || sc < 0 || sc >= ncol || visited[sr][sc] || image[sr][sc] != color) return;

        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        helper(image, visited, sr + 1, sc, color, newColor);
        helper(image, visited, sr - 1, sc, color, newColor);
        helper(image, visited, sr, sc + 1, color, newColor);
        helper(image, visited, sr, sc - 1, color, newColor);
    }
};

int main() {
    Solution s;
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    s.floodFill(image, 1, 1, 1);
    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[0].size(); ++j) 
            cout << image[i][j] << " ";
        cout << "\n";
    }
}