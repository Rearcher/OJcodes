/* convert sorted array to binary search tree */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    var n = nums.length;
    if (n === 0) return null;
    
    var idx = Math.floor(n/2);
    
    var root = new TreeNode(nums[idx]);
    root.left = sortedArrayToBST(nums.slice(0,idx));
    root.right = sortedArrayToBST(nums.slice(idx+1, n));
    
    return root;
};
