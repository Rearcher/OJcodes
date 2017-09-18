// binary tree paths
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */

function dfs(root, result, results) {
    if (!root) return;
    if (!root.left && !root.right) {
        results.push(result.join(''));
        return;
    }
    
    if (root.left !== null) {
        result.push("->"+root.left.val.toString());
        dfs(root.left, result, results);
        result.pop();
    }
    if (root.right !== null) {
        result.push("->"+root.right.val.toString());
        dfs(root.right, result, results);
        result.pop();
    }
    
    return;
} 
 
var binaryTreePaths = function(root) {
    var results = [];
    if (root === null) return results;
    
    var result = [root.val.toString()];
    if (root.left) {
        result.push("->"+root.left.val.toString());
        dfs(root.left, result, results);
        result.pop();
    }
    
    if (root.right) {
        result.push("->"+root.right.val.toString());
        dfs(root.right, result, results);
    }
    
    if (results.length === 0) {
        results.push(result.join(''));
    }
    return results;
};
