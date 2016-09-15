/*
 * 45. Jump Game II
 */
public class Solution {
    public int jump(int[] nums) {
        int cnt = 0, i = 0, n = nums.length;
        if (n == 1) return 0;
        while (i < n) {
            if (i + nums[i] >= n - 1) break;
            int max = 0, pos = -1;
            for (int j = 1; j <= nums[i]; ++j) {
                if (j + nums[i + j] > max) {
                    max = j + nums[i + j];
                    pos = i + j;
                }
            }
            i = pos;
            cnt++;
        }
        return cnt + 1;
    }
}
