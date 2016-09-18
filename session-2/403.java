/*
 * 403. Frog Jump
 */
public class Solution {
    private boolean backtracking(int[] stones, int pos, int k, int i) {
        if (i >= stones.length) return true;
        if (pos + k + 1 < stones[i]) return false;

        int j = i;
        while (j < stones.length && pos + k + 1 > stones[j]) j++;
        if (j < stones.length && pos + k + 1 == stones[j]) {
            if (backtracking(stones, pos + k + 1, k + 1, j + 1))
                return true;
        }

        j = i;
        while (j < stones.length && pos + k > stones[j]) j++;
        if (j < stones.length && pos + k == stones[j]) {
            if (backtracking(stones, pos + k, k, j + 1))
                return true;
        }

        j = i;
        while (j < stones.length && pos + k - 1 > stones[j]) j++;
        if (j < stones.length && pos + k - 1 == stones[j]) {
            if (backtracking(stones, pos + k - 1, k - 1, j + 1))
                return true;
        }

        return false;
    }

    public boolean canCross(int[] stones) {
        if (stones.length <= 1) return true;
        if (stones[0] + 1 < stones[1]) return false;

        return backtracking(stones, stones[1], 1, 2);
    }
}
