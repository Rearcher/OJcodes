// 330. Patching Array
// let miss become the smallest number we can't achieve
// it means [0, miss) is the range we can compute
// so, compare miss and the current position number in nums[]
// if nums[i] >= miss, we just add miss, so the range becomes [0, miss+miss)
// else nums[i] < miss, we just add nums[i], so the range becomes [0, miss+nums[i])
// until miss >= n
public class Solution {
    public int minPatches(int[] nums, int n) {
        long miss = 1;
        int added = 0, i = 0;
        int len = nums.length;
        while (miss <= n) {
            if (i < len && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss <<= 1;
                added++;
            }
        }
        return added;
    }
}
