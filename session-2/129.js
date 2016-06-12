/**
 * sum root to leaf numbers
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
    var res = 0;
    var str = [];
    
    if (!root) {
        return res;
    }
    
    str.push(root.val);
    
    var dfs = function (curNode) {
        if (!curNode.left && !curNode.right) {
            res += (+str.join(''));
            return;
        }
        
        if (curNode.left) {
            str.push(curNode.left.val);
            dfs(curNode.left);
            str.pop();
        }
        
        if (curNode.right) {
            str.push(curNode.right.val);
            dfs(curNode.right);
            str.pop();
        }
    };
    
    dfs(root);
    
    return res;
};
