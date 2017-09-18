/*
 * 402. Remove K Digits
 */
public class Solution {
    private String removeOneDigit(String num) {
        if (num.length() == 1) return "0";
        if (num.length() >= 2 && num.charAt(1) == '0') {
            int idx = 1;
            while (idx < num.length() && num.charAt(idx) == '0')
                idx++;
            String res = num.substring(idx);
            if (res.equals("")) return "0";
            return res;
        }

        int i = 0;
        while (i < num.length() - 1 && num.charAt(i) <= num.charAt(i+1))
            i++;
        return num.substring(0, i) + num.substring(i + 1);
    }

    public String removeKdigits(String num, int k) {
        if (num.length() == k) return "0";
        while (k > 0) {
            num = removeOneDigit(num);
            k--;
        }
        return num;
    }
}
