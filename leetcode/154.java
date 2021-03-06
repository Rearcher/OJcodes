// find minimum in rotated sorted array II
public class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];

            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[left]) {
                left++;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
}
