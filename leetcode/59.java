// spiral matrix
public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, j = -1, dir = 0;
        for (int num = 1; num <= n * n;) {
            int new_i = i + directions[dir][0];
            int new_j = j + directions[dir][1];
            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) {
                dir = (dir + 1) % 4;
            } else if (res[new_i][new_j] == 0) {
                res[new_i][new_j] = num;
                i = new_i;
                j = new_j;
                num++;
            } else {
                dir = (dir + 1) % 4;
            }
        }

        return res;
    }
}
