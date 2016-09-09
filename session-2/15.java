/*
 * 15. 3Sum
 */ 
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        if (nums.length < 3) return res;

        Arrays.sort(nums);
        int i = 0;
        while (i < nums.length - 2) {
            if (nums[i] > 0) break;
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                if (sum <= 0) while (nums[j] == nums[++j] && j < k);
                if (sum >= 0) while (nums[k] == nums[--k] && j < k);
            }
            while (nums[i] == nums[++i] && i < nums.length - 2);
        }
        return res;
    }
}
