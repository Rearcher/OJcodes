// Counting Bits
public class Solution {
    public int[] countBits(int num) {
        int[] ans = new int[num+1];
       if (num >= 0) ans[0] = 0;
        if (num >= 1) ans[1] = 1;
        if (num >= 2) ans[2] = 1;
        if (num >= 3) ans[3] = 2;

        int begin = 2, end = 3;
        while (end < num) {
            int len = end - begin + 1;
            int newBegin = end+1;
            int newEnd = len * 2 + newBegin - 1;

            for (int i = newBegin; i <= num && i <= newEnd; i++) {
                if (i < newBegin + len) {
                    ans[i] = ans[i - len];
                } else {
                    ans[i] = ans[i - len] + 1;
                }
            }

            begin = newBegin;
            end = newEnd;
        }
        return ans;
    }
}
