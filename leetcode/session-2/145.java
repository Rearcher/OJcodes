/**
 * Binary Tree Postorder Traversal
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode curNode = root, prev = null;
        Stack<TreeNode> stack = new Stack<>();

        while (curNode != null || !stack.isEmpty()) {
            if (curNode != null) {
                stack.push(curNode);
                curNode = curNode.left;
            } else {
                TreeNode temp = stack.peek();
                if (temp.right != null && prev != temp.right) {
                    curNode = temp.right;
                } else {
                    stack.pop();
                    res.add(temp.val);
                    prev = temp;
                }
            }
        }

        return res;
    }
}
