// Find Minumum in Rotated Sorted Array
public class Solution {
	// origin version
	public int findMin(int[] nums) {
        if (nums.length == 1) return nums[0];
        else if (nums.length == 2) return Math.min(nums[0], nums[1]);

        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[0] < nums[mid] && nums[mid] < nums[nums.length - 1]) {
                return nums[0];
            } else if (nums[0] > nums[mid] && nums[mid] > nums[nums.length - 1]) {
                return nums[nums.length - 1];
            }

            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else if (nums[mid] == nums[0]) {
                return nums[right];
            } else {
                if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                } else {
                    right = mid - 1;
                }
            }
        }

        return nums[left];
    }




	// better    
	public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];

            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }

	
}
