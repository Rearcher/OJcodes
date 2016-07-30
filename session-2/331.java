// Verify PreorderSerialization of a Binary Tree
// using outdegree & indegree
public class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        int diff = 1;
        for (String s : nodes) {
            if (--diff < 0) return false;
            if (!s.equals("#")) diff += 2;
        }
        return diff == 0;
    }
}

// using stack
public class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        Stack<String> stack = new Stack<>();

        for (String s : nodes) {
            if (s.equals("#")) {
                while (!stack.isEmpty() && stack.peek().equals("#")) {
                    stack.pop();
                    if (stack.isEmpty()) return false;
                    stack.pop();
                }
                stack.push(s);
            } else {
                stack.push(s);
            }
        }
        return stack.size() == 1 && stack.peek().equals("#");
    }
}
