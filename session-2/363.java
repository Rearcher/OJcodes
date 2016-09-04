/* 363. Max Sum of Rectangle No Larger Than K
 * it can be convert to another sub problem: 
 * given a array, find a subarray that contains the largest sum less than k
 * we use curSums[0...n], curSums[i] means the sum from 0 to i
 * so when we need subarray sum such like i to j, we can compute it by curSums[j] - curSums[i]
 * so when we need to find curSums[j] - curSums[i] <= k, we only need to find the ceiling of (curSums[j] - k)
 * what a nice solution!
 */ 
public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if (matrix.length == 0) return 0;

        int row = matrix.length, col = matrix[0].length;
        int result = Integer.MIN_VALUE;

        for (int left = 0; left < col; ++left) {
            
            // sums[] stores current row sums from left to right
            int[] sums = new int[row];
            for (int right = left; right < col; ++right) {
                for (int i = 0; i < row; ++i)
                    sums[i] += matrix[i][right];

                TreeSet<Integer> set = new TreeSet<Integer>();
                set.add(0);
                int curSum = 0;

                for (int sum : sums) {
                    curSum += sum;
                    Integer num = set.ceiling(curSum - k);
                    if (num != null) result = Math.max(result, curSum - num);
                    set.add(curSum);
                }
            }
        }
        return result;
    }
}
