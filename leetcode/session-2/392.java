// 392. Is Subsequence
public class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() > t.length()) return false;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++; j++;
            } else {
                j++;
            }
        }
        if (i < s.length()) return false;
        return true;
    }
}
