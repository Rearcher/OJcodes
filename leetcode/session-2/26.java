// remove duplicates from sorted array
public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int i = 0, j = 1;
        while (j < nums.length) {
            while (j < nums.length && nums[j] == nums[i])
                j++;
            if (j >= nums.length) break;
            nums[i + 1] = nums[j];
            i++;
            j++;
        }
        return i + 1;
    }
}
