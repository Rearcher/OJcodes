/*
 * 71. Simplify Path
 */
public class Solution {
    public String simplifyPath(String path) {
        String[] dirs = path.split("/");
        Stack<String> stack = new Stack<>();

        for (String dir : dirs) {
            if (dir.equals(".") || dir.equals(""))
                continue;
            else if (dir.equals("..")) {
                if (!stack.empty()) stack.pop();
            }
            else {
                stack.push(dir);
            }
        }

        if (stack.empty()) return "/";
        StringBuilder res = new StringBuilder();
        while (!stack.empty()) {
            res.insert(0, stack.pop());
            res.insert(0, '/');
        }
        return res.toString();
    }
}
