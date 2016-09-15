/*
 * 41. First Missing Positive
 */
public class Solution {
    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public int firstMissingPositive(int[] nums) {
        int n = nums.length, i = 0;
        while (i < n) {
            if (nums[i] == i + 1 || nums[i] <= 0 || nums[i] > n) {
                i++;
            } else {
                if (nums[nums[i] - 1] != nums[i])
                    swap(nums, i, nums[i] - 1);
                else
                    i++;
            }
        }
        i = 0;
        while (i < n && nums[i] == i + 1)
            i++;
        return i + 1;
    }
}
