// different ways to add parentheses
public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < input.length(); ++i) {
            char c = input.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                String leftPart = input.substring(0, i);
                String rightPart = input.substring(i + 1);

                List<Integer> leftRes = diffWaysToCompute(leftPart);
                List<Integer> rightRes = diffWaysToCompute(rightPart);

                for (Integer r : leftRes) {
                   for (Integer s : rightRes) {
                       switch(c) {
                           case '+':
                               res.add(r+s);
                               break;
                           case '-':
                               res.add(r-s);
                               break;
                           case '*':
                               res.add(r*s);
                       }
                   }
                }
            }
        }
        if (res.size() == 0) res.add(Integer.valueOf(input));
        return res;
    }
}
