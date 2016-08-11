// Letter Combinations of a Phone Number
public class Solution {
    private final char[][] maps = {{' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
            {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}, {'*'}, {'#'}};


    private void backtracking(List<String> res, String digits, int index, StringBuilder temp) {
        if (index >= digits.length()) {
            if (temp.length() > 0) res.add(temp.toString());
            return;
        }

        int idx = 0;
        char c = digits.charAt(index);
        if (c >= '0' && c <= '9') {
            idx = c - '0';
        } else if (c == '*') {
            idx = 10;
        } else if (c == '#') {
            idx = 11;
        }

        if (idx == 1) {
            backtracking(res, digits, index + 1, temp);
        } else {
            for (int i = 0; i < maps[idx].length; ++i) {
                temp.append(maps[idx][i]);
                backtracking(res, digits, index + 1, temp);
                temp.deleteCharAt(temp.length() - 1);
            }
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        backtracking(res, digits, 0, new StringBuilder());
        return res;
    }
}
