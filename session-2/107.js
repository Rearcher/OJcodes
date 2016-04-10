// binary tree level order traversal
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    var results = [];
    if (root === null) return results;
    
    var levelNodes = [], levelValues = [];
    levelNodes.push(root);
    levelValues.push(root.val);
    results.push(levelValues);
    
    while (levelNodes.length > 0) {
        levelValues = [];
        var newLevelNodes = [];
        for (var i = 0; i < levelNodes.length; i++) {
            if (levelNodes[i].left !== null) {
                newLevelNodes.push(levelNodes[i].left);
                levelValues.push(levelNodes[i].left.val);
            }
            if (levelNodes[i].right !== null) {
                newLevelNodes.push(levelNodes[i].right);
                levelValues.push(levelNodes[i].right.val);
            }
        }
        if (levelValues.length > 0) results.push(levelValues);
        levelNodes = newLevelNodes;
    }
    
    return results.reverse();
};
