// symmetric tree
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
function childSymmetric(left, right) {
    if (left === null && right === null) return true;
    if ((left !== null && right === null) || 
        (left === null && right !== null)) return false;
    
    if (left.val != right.val) return false;
    else {
        return childSymmetric(left.right, right.left) && childSymmetric(left.left, right.right);
    }
} 

var isSymmetric = function(root) {
    if (root === null) return true;
    return childSymmetric(root.left, root.right);
};
