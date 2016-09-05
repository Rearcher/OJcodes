// 394. Decode String
public class Solution {
    public String decodeString(String s) {
        int n = s.length(), i = 0;
        Stack<String> stringStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();

        while (i < n) {
            char c = s.charAt(i);
            StringBuilder temp = new StringBuilder();
            if (Character.isAlphabetic(c)) {
                while (i < n && Character.isAlphabetic(s.charAt(i))) {
                    temp.append(s.charAt(i));
                    i++;
                }
                stringStack.push(temp.toString());
            } else if (Character.isDigit(c)) {
                while (Character.isDigit(s.charAt(i))) {
                    temp.append(s.charAt(i));
                    i++;
                }
                numStack.push(Integer.parseInt(temp.toString()));
            } else if (c == '[') {
                int j = i++;
                while (Character.isAlphabetic(s.charAt(i))) {
                    i++;
                }
                stringStack.push(s.substring(j, i));
            } else if (c == ']') {
                String str = stringStack.pop();
                int num = numStack.pop();
                while (num-- > 0) temp.append(str.substring(1));

                if (!stringStack.empty() && stringStack.peek().charAt(0) == '[') {
                    stringStack.push(stringStack.pop() + temp.toString());
                } else {
                    stringStack.push(temp.toString());
                }
                i++;
            }
        }

        StringBuilder res = new StringBuilder();
        while (!stringStack.empty())
            res.insert(0, stringStack.pop());
        return res.toString();
    }
}
