/*
 * 54. Spiral Matrix
 */
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int[][] dirs = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        List<Integer> res = new LinkedList<>();

        int row = matrix.length;
        if (row == 0) return res;
        int col = matrix[0].length, i = 0, j = 0;
        boolean[][] visited = new boolean[row][col];

        int dir = 0;
        while (true) {
            res.add(matrix[i][j]);
            visited[i][j] = true;

            int next_i = i + dirs[dir][0];
            int next_j = j + dirs[dir][1];
            if (next_i < 0 || next_i >= row || next_j < 0 || next_j >= col || visited[next_i][next_j]) {
                dir = (dir + 1) % 4;
                next_i = i + dirs[dir][0];
                next_j = j + dirs[dir][1];
                if (next_i < 0 || next_i >= row || next_j < 0 || next_j >= col || visited[next_i][next_j])
                    break;
            }
            i = next_i;
            j = next_j;
        }

        return res;
    }
}
