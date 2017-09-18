// Count of Smaller Numbers After Self
public class Solution {
    class Node {
        Node left, right;
        int val, sum, dup = 1;
        public Node(int v, int s) {
            this.val = v;
            this.sum = s;
        }
    }

    private Node insert(int num, Node node, Integer[] ans, int i, int preSum) {
        if (node == null) {
            node = new Node(num, 0);
            ans[i] = preSum;
        } else if (node.val == num) {
            node.dup++;
            ans[i] = preSum + node.sum;
        } else if (node.val > num) {
            node.sum++;
            node.left = insert(num, node.left, ans, i, preSum);
        } else {
            node.right = insert(num, node.right, ans, i, preSum + node.dup + node.sum);
        }
        return node;
    }
    
    public List<Integer> countSmaller(int[] nums) {
        if (nums.length <= 0) return new ArrayList<Integer>();
        Integer[] res = new Integer[nums.length];
        Node root = null;
        for (int i = nums.length - 1; i >= 0; --i) {
            root = insert(nums[i], root, res, i, 0);
        }
        return Arrays.asList(res); 
    }
}
