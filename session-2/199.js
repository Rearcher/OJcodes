/* binary tree right side view */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    if (!root) return [];
    
    var levelNodes = [root], aux = [];
    var res = [];
    
    while (levelNodes.length > 0) {
        var tmp = levelNodes.pop();
        res.push(tmp.val);
        levelNodes.push(tmp);
        for (var i = 0; i < levelNodes.length; i += 1) {
            if (levelNodes[i].left) aux.push(levelNodes[i].left);
            if (levelNodes[i].right) aux.push(levelNodes[i].right);
        }
        levelNodes = aux.slice(0);
        aux = [];
    }
    
    return res;
};
