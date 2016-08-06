/**
 * Largest Divisible Subset
 * 一个数，可以加到当前的集合中去的条件：可以整除当前集合中最小的元素 or 可以被当前集合中最大的元素整除
 * 为了方便判断最大最小元素，先将所有的元素按从小到大的顺序排序
 * dp[n]表示以nums[n]为最小元素的集合的元素个数
 * 从原始集合尾部开始遍历，当前位置当前元素是需要新加的元素，内层循环从当前位置开始向后遍历
 * 新加的元素肯定比已有集合中的元素都小，所以只要根据已有集合的最小元素能否被当前元素整除来判断
 * 另外需要用backtracking[i]记录dp[i]更新前的最小值的位置
 * 用max记录当前最大长度的子集，如果max发生变化，说明更长的子集出现，需要记录更长子集的初始位置，即当前i
 * @param nums
 * @return
 */
public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);

        int[] dp = new int[nums.length];
        int[] backtracking = new int[nums.length];

        int max = 0, pos = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            for (int j = i; j < nums.length; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    backtracking[i] = j;

                    if (dp[i] > max) {
                        max = dp[i];
                        pos = i;
                    }
                }
            }
        }

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < max; ++i) {
            res.add(nums[pos]);
            pos = backtracking[pos];
        }

        return res;
    }
}
