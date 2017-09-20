// path sum
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if (!root) return false;
    if (!root.right && !root.left) {
        if (sum - root.val === 0) return true;
        else return false;
    }
    
    return hasPathSum(root.left, sum-root.val) ||
           hasPathSum(root.right, sum-root.val);
};