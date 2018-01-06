/* 44. Wildcard Matching
 *
 */ 
public class Solution {
    public boolean isMatch(String s, String p) {
        int i = 0, j = 0;
        int star = -1, ii = i;

        while (i < s.length()) {

            if (j < p.length()) {
				// advance both two pointers if current position character equals
                if (p.charAt(j) == '?' || s.charAt(i) == p.charAt(j)) {
                    i++;
                    j++;
                    continue;
                }
				
				// if p[j] == '*', record the '*' index, only advance p pointer
                if (p.charAt(j) == '*') {
                    star = j++;
                    ii = i;
                    continue;
                }
            }
			
			// current character didn't match, last pattern was '*', current pattern is not '*'
            if (star != -1) {
                j = star + 1;
                i = ++ii;
                continue;
            }
			
			// current p character not *, last p character not *, character not match
            return false;
        }

        while (j < p.length() && p.charAt(j) == '*')
            j++;

        return j >= p.length();
    }
}
