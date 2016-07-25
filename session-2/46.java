// permutations
public class Solution {
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void permuteHelper(int[] nums, int begin, List<List<Integer>> res) {
        if (begin >= nums.length) {
            List<Integer> temp = new ArrayList<>();
            for (int i = 0; i < nums.length; ++i)
                temp.add(nums[i]);
            res.add(temp);
            return;
        }

        for (int i = begin; i < nums.length; ++i) {
            swap(nums, i, begin);
            permuteHelper(nums, begin + 1, res);
            swap(nums, i, begin);
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        permuteHelper(nums, 0, res);
        return res;
    }
}
