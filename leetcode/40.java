// Combination Sum II
public class Solution {
    private void backtracking(int[] candidates, int target, int begin, List<Integer> singleRes, List<List<Integer>> res, int temp) {
        if (temp > target) return;
        else if (temp == target) {
            res.add(new ArrayList<>(singleRes));
            return;
        }

        for (int i = begin; i < candidates.length; ++i) {
            if (i > begin && candidates[i] == candidates[i - 1]) continue;
            singleRes.add(candidates[i]);
            backtracking(candidates, target, i + 1, singleRes, res, temp + candidates[i]);
            singleRes.remove(singleRes.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        backtracking(candidates, target, 0, new ArrayList<>(), res, 0);
        return res;
    }
}
