/*
 * 65. Valid Number
 */
public class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        int len = s.length();

        boolean pointSeen = false;
        boolean eSeen = false;
        boolean numberSeen = false;
        boolean numberAfterE = true;

        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if (c == '.') {
                if (eSeen || pointSeen)
                    return false;
                pointSeen = true;
            } else if (c == 'e') {
                if (eSeen || !numberSeen)
                    return false;
                numberAfterE = false;
                eSeen = true;
            } else if (c == '-' || c == '+') {
                if (i != 0 && s.charAt(i - 1) != 'e')
                    return false;
            } else {
                return false;
            }
        }

        return numberSeen && numberAfterE;
    }
}
