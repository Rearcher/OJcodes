// 3Sum Closest
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if (nums.length < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        Arrays.sort(nums);
        
        for (int first = 0; first < nums.length - 2; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int third = nums.length - 1;
            while (second < third) {
                int temp = nums[first] + nums[second] + nums[third];
                if (temp == target) return temp;
                if (Math.abs(target - temp) < Math.abs(target - closest))
                    closest = temp;
                if (temp > target) --third;
                else ++second;
            }
        }
        return closest;
    }
}
