// Wiggle Subsequence
public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length <= 1)
            return nums.length;

        int res = 0;
        int lastSign = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] > nums[i-1] && (lastSign == 0 || lastSign == -1)) {
                lastSign = 1;
                res++;
            } else if (nums[i] < nums[i-1] && (lastSign == 0 || lastSign == 1)) {
                lastSign = -1;
                res++;
            }
        }
        return res+1;
    }
}
