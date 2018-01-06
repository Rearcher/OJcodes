// 85. Maximal Rectangle
public class Solution {
    /* for one row:
     * left[i] means the left boundary at position i;
     * right[i] means the right boundary at position i;
     * height[i] means the height at position i;
     *
     * how to update:
     * assume we at row i and column j,
     * compute current row's cur_left[] and cur_right[] by iterating,
     * what's more, we need to consider last row's last_left[] and last_right[]
     * if matrix[i][j] == '1'
     *      left[i] = max(last_left[i], cur_left[i])
     *      right[i] = min(last_right[i], cur_right[i])
     *      height[i] = last_height[i] + 1;
     * else
     *      left[i] = 0
     *      right[i] = (number of columns)
     *      height[i] = 0
     */
    public int maximalRectangle(char[][] matrix) {

        if (matrix.length == 0) return 0;

        int row = matrix.length, col = matrix[0].length;
        int[] left = new int[col];
        int[] right = new int[col];
        int[] height = new int[col];

        // right initialization
        Arrays.fill(right, col);
        int maxArea = 0;

        for (int i = 0; i < row; ++i) {

            int cur_left = 0, cur_right = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') left[j] = Math.max(left[j], cur_left);
                else {left[j] = 0; cur_left = j + 1;}
            }
            for (int j = col - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = Math.min(right[j], cur_right);
                else {right[j] = col; cur_right = j;}
            }

            for (int j = 0; j < col; ++j)
                maxArea = Math.max(maxArea, (right[j] - left[j]) * height[j]);
        }

        return maxArea;
    }

}
