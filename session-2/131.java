// Palindrome Partitioning
public class Solution {
    private boolean isPalindrome(String s, int begin, int end) {
        while (begin < end) {
            if (s.charAt(begin) != s.charAt(end))
                return false;
            begin++;
            end--;
        }
        return true;
    }

    private void backtracking(String s, int begin, List<String> singleRes, List<List<String>> res) {
        if (begin >= s.length()) {
            res.add(new ArrayList<>(singleRes));
            return;
        }

        for (int i = begin; i < s.length(); ++i) {
            if (isPalindrome(s, begin, i)) {
                singleRes.add(s.substring(begin, i + 1));
                backtracking(s, i + 1, singleRes, res);
                singleRes.remove(singleRes.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        backtracking(s, 0, new ArrayList<>(), res);
        return res;
    }
}
