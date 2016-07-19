// House Robber II
public class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        if (nums.length == 1) {
            return nums[0];
        }
        
        int pre1 = 0, cur1 = 0;
        for (int i = 0; i < nums.length-1; ++i) {
            int temp = pre1;
            pre1 = cur1;
            cur1 = Math.max(temp + nums[i], pre1);
        }
        
        int pre2 = 0, cur2 = 0;
        for (int i = 1; i < nums.length; ++i) {
            int temp = pre2;
            pre2 = cur2;
            cur2 = Math.max(temp + nums[i], pre2);
        }
        
        return Math.max(cur1, cur2);
    }
}
