// Lexicographical Numbers
public class Solution {
   private void backtracking(int n, List<Integer> res, int num, int pos) {
        res.add(num);
        int begin = (pos == 0) ? 1 : 0;
        for (int i = begin; i <= 9; ++i) {
            if (num * 10 + i <= n)
                backtracking(n, res, num * 10 + i, pos + 1);
        }
    }

    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        backtracking(n, res, 0, 0);
        return res.subList(1, res.size());
    }
}
