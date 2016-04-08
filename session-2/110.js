/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

// top_down
function depth(root) {
    if (root === null) return 0;
    return Math.max(depth(root.left), depth(root.right))+1;
}

var isBalanced = function(root) {
   if (root === null) return true;
   
   var left = depth(root.left);
   var right = depth(root.right);
   
   return Math.abs(left-right)<=1 && isBalanced(root.left) && isBalanced(root.right);
};

// bottom_up
function dfsDepth(root) {
    if (root === null) return 0;
    
    var leftHeight = dfsDepth(root.left);
    if (leftHeight === -1) return -1;
    var rightHeight = dfsDepth(root.right);
    if (rightHeight === -1) return -1;
    
    if (Math.abs(leftHeight - rightHeight) > 1) return -1;
    return Math.max(leftHeight, rightHeight)+1;
}

var isBalanced = function(root) {
    return dfsDepth(root) !== -1;
};
