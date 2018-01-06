/*
 * 93. Restore IP Addresses
 */
public class Solution {
    private void backtracking(List<String> res, List<String> singleRes, String s, int begin) {

        if (begin >= s.length()) {
            if (singleRes.size() == 4)
                res.add(String.join(".", singleRes));
            return;
        }

        if (singleRes.size() >= 4) return;

        for (int len = 1; len <= 3; ++len) {
            if (begin + len > s.length()) return;
            String str = s.substring(begin, begin + len);
            if (str.length() >= 2 && str.charAt(0) == '0') continue;
            if (len <= 2 || Integer.parseInt(str) <= 255) {
                singleRes.add(str);
                backtracking(res, singleRes, s, begin + len);
                singleRes.remove(singleRes.size() - 1);
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        backtracking(res, new ArrayList<>(), s, 0);
        return res;
    }
}
