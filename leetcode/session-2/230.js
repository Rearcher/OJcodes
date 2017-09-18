/* kth smallest element in bst */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    
    var stack = [], ans = [];
    var curNode = root;
    
    while((curNode || stack.length > 0) && ans.length <= k) {
        if (curNode) {
            stack.push(curNode);
            curNode = curNode.left;
        } else {
            var temp = stack.pop();
            ans.push(temp.val);
            if (temp.right) {
                curNode = temp.right;
            }
        }
    }
    
    return ans[k-1];
};
