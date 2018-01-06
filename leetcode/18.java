/*
 * 18. 4Sum
 */ 
public class Solution {
    public List<List<Integer>> threeSum(int[] nums, int begin, int end, int target) {
        List<List<Integer>> res = new LinkedList<>();
        if (end - begin + 1 < 3) return res;
        
        int i = begin;
        while (i < end - 1) {
            int j = i + 1, k = end;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                if (sum <= target) while (nums[j] == nums[++j] && j < k);
                if (sum >= target) while (nums[k] == nums[--k] && j < k);
            }
            while (nums[i] == nums[++i] && i < end - 1);
        }
        return res;
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new LinkedList<>();
        if (nums.length < 4) return res;

        Arrays.sort(nums);
        int i = 0;
        while (i <= nums.length - 4) {
            
            List<List<Integer>> temp = threeSum(nums, i+1, nums.length-1, target-nums[i]);
            for (List<Integer> list : temp) {
                List<Integer> singleRes = new ArrayList<>();
                singleRes.add(nums[i]);
                singleRes.addAll(list);
                res.add(singleRes);
            }
            i++;
            while (nums[i] == nums[i-1] && i <= nums.length - 4) i++;
            
        }

        return res;
    }
}
