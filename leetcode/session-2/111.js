// minimum depth of binary tree
/**
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

var minDepth = function(root) {
    if (!root) return 0;
    
    var levelNodes = [root];
    var nextLevelNodes = [];
    var depth = 0;
    var isLeaf = false;
    
    while (!isLeaf && levelNodes.length > 0) {
        depth += 1;
        levelNodes.forEach(function (levelNode) {
            if (!levelNode.left && !levelNode.right) {
                isLeaf = true;
            } 
            if (levelNode.left) nextLevelNodes.push(levelNode.left);
            if (levelNode.right) nextLevelNodes.push(levelNode.right);
        });
        
        levelNodes = nextLevelNodes.slice(0);
        nextLevelNodes = [];
    }
    
    return depth;
};
