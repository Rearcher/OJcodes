/*
 * 60. Permutation Sequence
 * relevent: 31. next permutation
 */
public class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> numbers = new LinkedList<>();
        int[] factorial = new int[n + 1];
        StringBuilder res = new StringBuilder();

        int sum = 1;
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            sum *= i;
            factorial[i] = sum;
        }

        for (int i = 1; i <= n; ++i)
            numbers.add(i);

        k--;
        for (int i = 1; i <= n; ++i) {
            int idx = k / factorial[n - i];
            res.append(numbers.get(idx));
            numbers.remove(idx);
            k -= idx * factorial[n - i];
        }

        return res.toString();
    }
}
