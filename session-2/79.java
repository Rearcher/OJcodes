/*
 * 79. Word Search
 */
public class Solution {
    static int[][] dirs = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    private boolean search(int i, int j, int k, char[][] board, boolean[][] visited, String word) {
        if (k >= word.length())
            return true;

        int row = board.length;
        int col = board[0].length;

        for (int[] dir : dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (new_i < 0 || new_i >= row || new_j < 0 || new_j >= col || visited[new_i][new_j] ||board[new_i][new_j] != word.charAt(k))
                continue;
            visited[new_i][new_j] = true;
            if (search(new_i, new_j, k+1, board, visited, word))
                return true;
            visited[new_i][new_j] = false;
        }
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int row = board.length;
        if (row == 0) return false;
        int col = board[0].length;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] != word.charAt(0))
                    continue;

                boolean[][] visited = new boolean[row][col];
                visited[i][j] = true;
                if (search(i, j, 1, board, visited, word))
                    return true;
            }
        }
        return false;
    }
}
