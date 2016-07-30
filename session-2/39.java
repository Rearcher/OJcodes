// Combination Sum
public class Solution {
    private void backtracking(int[] candidates, List<Integer> singleRes, List<List<Integer>> res, int cnt, int begin, int target) {
        if (cnt == target) {
            res.add(new LinkedList<>(singleRes));
        }

        for (int i = begin; i < candidates.length; ++i) {
            if (cnt + candidates[i] > target) continue;
            singleRes.add(candidates[i]);
            backtracking(candidates, singleRes, res, cnt + candidates[i], i, target);
            singleRes.remove(singleRes.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        backtracking(candidates, new ArrayList<>(), res, 0, 0, target);
        return res;
    }
}
