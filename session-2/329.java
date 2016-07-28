// Longest Increasing Path in a Matrix
public class Solution {
    private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    private int dfs(int[][] matrix, int i, int j, int rows, int cols, int[][] cache) {
        if (cache[i][j] != 0) return cache[i][j];
        int max = 1;

        for (int[] dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] <= matrix[i][j])
                continue;
            int len = 1 + dfs(matrix, x, y, rows, cols, cache);
            max = Math.max(max, len);
        }
        cache[i][j] = max;
        return max;
    }
    
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0) return 0;
        int rows = matrix.length, cols = matrix[0].length;

        int[][] cache = new int[rows][cols];
        int ans = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int len = dfs(matrix, i, j, rows, cols, cache);
                ans = Math.max(len, ans);
            }
        }
        return ans;
    }
}
