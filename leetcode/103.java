/**
 * Binary Tree Zigzag Level Order Traversal
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private void dfs(TreeNode curNode, List<List<Integer>> res, int level) {
        if (curNode == null) return;
        
        if (res.size() <= level) res.add(new LinkedList<>());
        
        List<Integer> list = res.get(level);
        if (level % 2 == 0) list.add(curNode.val);
        else list.add(0, curNode.val);
        
        dfs(curNode.left, res, level + 1);
        dfs(curNode.right, res, level + 1);
    }
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(root, res, 0);
        return res;
    }
}
